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

// My Approach
class Solution {
private:
    void preorder(TreeNode* root, vector<int> &arr){
        if (root == nullptr) {
            arr.push_back(-1);
            return;
        }
        arr.push_back(root->val);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
    void revPreorder(TreeNode* root, vector<int> &arr){
        if (root == nullptr){
            arr.push_back(-1);
            return;
        }
        arr.push_back(root->val);
        revPreorder(root->right, arr);
        revPreorder(root->left, arr);
    }
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> pre, revPre;
        preorder(root->left, pre);
        revPreorder(root->right, revPre);
        return pre == revPre;
    }
};

// Striver's Approach
class Solution {
private:
    bool solve(TreeNode* root1, TreeNode* root2){
        if (root1 == nullptr || root2 == nullptr){
            return root1 == root2;
        }
        if (root1 -> val != root2 -> val) return false;
        // cout << root1->val << ' ' << root2->val << '\n';
        return (solve(root1->left, root2->right) &&
                solve(root1->right, root2->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return (root == nullptr || solve(root->left, root->right));
    }
};