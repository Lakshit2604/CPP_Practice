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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        vector<int> ans;
        TreeNode* node = (root != nullptr) ? root -> left : nullptr;
        while(!st.empty() || node ){
            if (node != nullptr){
                st.push(node);
                node = node -> left;
            }
            else {
                node = st.top();
                ans.push_back(node -> val);
                st.pop();
                node = node -> right;
            }
        }
        return ans;
    }
};