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
    bool solve(TreeNode* root, long min, long max){
        if (!root) return true;
        if ( root-> val > min && root -> val < max){
            return (
                solve(root->left, min, root->val) && 
                solve(root->right, root->val, max)
            );
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, (long)INT_MIN -1, (long)INT_MAX + 1);
    }
};