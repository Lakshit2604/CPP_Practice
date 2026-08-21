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
    TreeNode* solve(int l, int h, int &j, unordered_map<int, int> &inMpp, vector<int> &inorder, vector<int> &postorder){
        if ( l > h) return nullptr;
        TreeNode* root = new TreeNode(postorder[j]);
        int i = inMpp[postorder[j]];
        j--;
        root -> right = solve(i+1,h,j,inMpp,inorder,postorder);
        root -> left = solve(l,i-1,j,inMpp,inorder,postorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int j = n-1;
        unordered_map <int, int> inMpp;
        for (int i = 0; i < n; i++) inMpp[inorder[i]] = i;
        return solve(0,n-1,j,inMpp,inorder,postorder);
    }
};