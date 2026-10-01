# include <iostream>
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

class Solution {
    TreeNode* solve(TreeNode* root){
        if ( !root->left && !root->right ) return nullptr;
        if ( !root -> left) return root -> right;
        TreeNode* temp = root -> left;
        while( temp -> right ){
            temp = temp -> right;
        }
        temp -> right = root -> right;
        return root -> left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = root;
        if (!root) return root;
        if (root->val == key) return solve(root);
        while(temp){
            if ( temp -> val > key){
                if ( temp -> left && temp -> left -> val == key){
                    temp -> left = solve(temp->left);
                    break;
                }
                else temp = temp -> left;
            }
            else{
                if (temp -> right && temp -> right -> val == key){
                    temp -> right = solve(temp -> right);
                    break;
                }
                else temp = temp -> right;
            }
        }
        return root;
    }
};