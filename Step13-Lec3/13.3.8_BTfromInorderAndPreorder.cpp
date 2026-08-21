#include <iostream>
# include <map>
# include <unordered_map>
# include <set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* solve(int l, int h, int &j,unordered_map<int, int> &inMpp, vector<int> &inorder,vector<int> &preorder){
        if ( l > h) return nullptr;
        int i = inMpp[preorder[j]];
        TreeNode* root = new TreeNode(preorder[j]);
        j++;
        root -> left = solve(l, i-1, j, inMpp,inorder, preorder);
        root -> right = solve(i+1, h, j, inMpp,inorder, preorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> inMpp;
        for (int i = 0; i < n; i++){
            inMpp[inorder[i]] = i;
        }
        int j = 0;
        return solve(0,n-1,j,inMpp, inorder, preorder);
    }
};