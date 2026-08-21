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

// iterative
class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack <TreeNode*> st;
        int maxi = 0;
        if (root != nullptr) st.push(root), maxi = 1;
        TreeNode * curr = root;
        while(!st.empty()){
            if (curr != nullptr){
                curr = curr -> left;
                if (curr) st.push(curr);
            }
            else {
                maxi = max(maxi, (int)st.size());
                TreeNode* temp = st.top();
                if (temp -> right != nullptr){
                    st.push(temp -> right);
                    curr = temp -> right;
                }
                else{
                    st.pop();
                    while (!st.empty() && temp == st.top() -> right){
                        temp = st.top();
                        st.pop();
                    }
                }
            }
        }
        return maxi;
    }
};

// recursive 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int ml = maxDepth(root->left);
        int mr = maxDepth(root->right);
        return 1 + max(ml,mr);
    }
};