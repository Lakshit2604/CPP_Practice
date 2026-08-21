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

// Brute
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if (root) st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr -> right) st.push(curr->right);
            if(curr -> left) st.push(curr->left);
            curr -> right = (!st.empty()) ? st.top() : nullptr;
            curr -> left = nullptr;
        }
    }
};

// Back Preorder Recursion 
class Solution {
    public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root -> right);
        flatten(root -> left);
        root -> right = prev;
        root -> left = nullptr;
        prev = root;
    }
};

// Morris Traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if ( !curr -> left) curr = curr -> right;
            else{
                TreeNode* prev = curr -> left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
                curr = curr->right;
            }
        }
    }
};