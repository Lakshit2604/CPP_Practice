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
    bool solve(TreeNode* root, int k, unordered_map <int, int> &mpp){
        if (!root) return false;
        if (mpp.find(k - (root->val)) != mpp.end()) return true;
        mpp[root->val] = 1;
        return solve(root->left, k, mpp) || solve(root->right, k, mpp);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map <int, int> mpp;
        return solve(root, k, mpp);
    }
};

// Optimal
class BSTIterator {
private:
    void pushAll(TreeNode* root, stack <TreeNode*> &st){
        if (!root) return;
        st.push(root);
        if (reverse) pushAll(root -> left, st);
        else pushAll(root -> right, st);
    }
public:
    stack<TreeNode*> st;
    bool reverse;
    BSTIterator(TreeNode* root, bool rev) {
        reverse = rev;
        pushAll(root, st);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (reverse) pushAll(top -> right, st);
        else pushAll(top -> left, st);
        return top -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        int left = l.next();
        int right = r.next();
        while (left < right){
            if (left + right == k) return true;
            else if (left + right < k) left = l.next();
            else right = r.next();
        }
        return false;
    }
};