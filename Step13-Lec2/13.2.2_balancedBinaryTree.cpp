#include <iostream>
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
private:
    int maxHeight(TreeNode* root){
        if (root == nullptr) return 0;
        int lh = maxHeight(root -> left);
        int rh = maxHeight(root -> right);
        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if ( root == nullptr) return true;
        int lh = maxHeight(root -> left);
        int rh = maxHeight(root -> right); 
        if (abs(lh - rh) > 1) return false;
        
        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);
        if ( !left || !right ) return false;
        return true;
    }
};

// Optimal
class Solution {
private:
    int maxHeight(TreeNode* root){
        if (root == nullptr) return 0;
        int lh = maxHeight(root -> left);
        int rh = maxHeight(root -> right);
        if ( lh == -1 || rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        int heightDiff = maxHeight(root);
        if (heightDiff == -1) return false;
        return true;
    }
};