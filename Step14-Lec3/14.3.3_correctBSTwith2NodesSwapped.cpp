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
private:
    void solve(TreeNode* root, vector<int> &inorder){
        if ( !root) return;
        solve(root -> left, inorder);
        inorder.push_back(root->val);
        solve(root -> right, inorder);
    }

    void solve(TreeNode* root, int n1, int n2){
        if (!root) return;
        solve(root -> left, n1, n2);
        if (root -> val == n1) root -> val = n2;
        else if (root -> val == n2 ) root -> val = n1;
        solve(root -> right, n1, n2);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        solve(root, inorder);
        int n1 = 0, n2 = 0;
        for (int i = 1; i < inorder.size(); i++){
            if ( inorder[i] < inorder[i-1]){
                n1 = inorder[i];
            }
        }
        for (int i = inorder.size()-2; i >= 0; i--){
            if ( inorder[i] > inorder[i+1]){
                n2 = inorder[i];
            }
        }
        solve(root, n1, n2);
    }
};

// Better 
class Solution {
private:
    void inord(TreeNode* root, TreeNode* &prev, TreeNode* &n){
        if (!root) return;
        inord(root -> left, prev, n);
        if ( prev && (prev -> val > root -> val)) n = root;
        prev = root;
        inord(root -> right, prev, n);
    }

    void oppInord(TreeNode* root, TreeNode* &prev, TreeNode* &n){
        if (!root) return;
        oppInord(root -> right, prev, n);
        if ( prev && (prev -> val < root -> val)) n = root, cout << root -> val;
        prev = root;
        oppInord(root -> left, prev, n);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* n1 = nullptr, *n2 = nullptr, *prev1 = nullptr, *prev2 = nullptr;
        inord(root, prev1, n1);
        oppInord(root, prev2, n2);
        int temp = n1 -> val;
        n1 -> val = n2 -> val;
        n2 -> val = temp;
    }
};

// Optimal
class Solution {
private:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last = nullptr;

    void inord(TreeNode* root){
        if (!root) return;
        inord(root -> left);
        if ( prev ){
            if ( prev -> val > root -> val){
                if ( first ) last = root;
                else {
                    first = prev;
                    middle = root;
                }
            }
        }
        prev = root;
        inord(root -> right);
    }

public:
    void recoverTree(TreeNode* root) {
        inord(root);
        if ( last ) swap(first-> val, last -> val);
        else swap (first -> val, middle -> val);
    }
};