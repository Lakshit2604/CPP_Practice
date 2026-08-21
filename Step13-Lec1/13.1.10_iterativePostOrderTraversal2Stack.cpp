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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack <TreeNode*> st1, st2;
        if(root != nullptr) st1.push(root);
        while(!st1.empty()){
            TreeNode* top = st1.top();
            st2.push(top);
            st1.pop();
            if (top -> left) st1.push(top -> left);
            if (top -> right) st1.push(top -> right);
        }
        while (!st2.empty()){
            ans.push_back(st2.top() -> val);
            st2.pop();
        }
        return ans;      
    }
};