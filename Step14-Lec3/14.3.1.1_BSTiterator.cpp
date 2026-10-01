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

// Optimal
class BSTIterator {
private:
    void pushLeft(TreeNode* root, stack <TreeNode*> &st){
        if (!root) return;
        st.push(root);
        pushLeft(root -> left, st);
    }
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushLeft(root, st);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        pushLeft(top -> right, st);
        return top -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};