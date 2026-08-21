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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> preorder;
        while ( curr != nullptr){
            TreeNode* prev = curr -> left;
            if (!prev){
                preorder.push_back(curr->val);
                curr = curr -> right;
            }
            else{
                while(prev->right && prev->right != curr){
                    prev = prev -> right;
                }
                if (!prev->right){
                    preorder.push_back(curr->val);
                    prev -> right = curr;
                    curr = curr -> left;
                }
                else{
                    prev -> right = nullptr;
                    curr = curr -> right;
                }
            }
        }
        return preorder;
    }
};