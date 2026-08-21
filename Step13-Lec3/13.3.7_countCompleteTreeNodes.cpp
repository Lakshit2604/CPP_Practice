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
    int lheight(TreeNode* root){
        if ( !root ) return 1;
        return lheight(root->left) + 1;
    }
    int rheight(TreeNode* root){
        if ( !root ) return 1;
        return rheight(root->right)+ 1;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lH = lheight(root->left);
        int rH = rheight(root->right);
        if ( lH == rH) return (1 << lH) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};