#include <iostream>
# include <sstream>
# include <string>
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

// Better
class Solution {
private:
    TreeNode* solve(int l, int h, int &j, vector<int>& preorder, vector<int>& inorder,unordered_map <int, int> mpp){
        if ( j >= preorder.size()) return nullptr;
        if ( l > h) return nullptr;
        int i = mpp[preorder[j]];
        TreeNode* root = new TreeNode(preorder[j]);
        j++;
        root -> left = solve(l, i-1, j, preorder, inorder, mpp);
        root -> right = solve(i+1, h, j, preorder, inorder, mpp);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map <int, int> mpp;
        int n = preorder.size();
        for (int i = 0; i < n; i++) mpp[inorder[i]] = i;
        int j = 0;
        return solve(0, n-1 ,j, preorder, inorder, mpp); 
    }
};

// Optimal
class Solution {
private:
    TreeNode* solve(int h, int &i, vector<int> &pre){
        cout << i << ' ';
        if ( i >= pre.size() || pre[i] > h) return nullptr;
        TreeNode* root = new TreeNode(pre[i]);
        i++;
        root -> left = solve(root->val, i, pre);
        root -> right = solve( h, i, pre);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(INT_MAX, i, preorder);
    }
};