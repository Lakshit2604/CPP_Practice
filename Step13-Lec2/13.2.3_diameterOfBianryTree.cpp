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
    int diameterOfBinaryTree(TreeNode* root) {
        if ( root == nullptr) return 0;
        int lh = maxHeight(root -> left);
        int rh = maxHeight(root -> right);
        int length= lh + rh;
        int left = diameterOfBinaryTree(root -> left);
        int right = diameterOfBinaryTree(root -> right);
        return max(length, max(left, right));
    }
};

// Optimal
class Solution {
private:
    int maxHeight(TreeNode* root, int &maxi){
        if (root == nullptr) return 0;
        int lh = maxHeight(root -> left, maxi);
        int rh = maxHeight(root -> right, maxi);
        maxi = max (maxi, lh+rh);
        return 1 + max(lh, rh);
    }    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if ( root == nullptr) return 0;
        int diameter = 0;
        int height = maxHeight(root, diameter);
        return diameter;
    }
};