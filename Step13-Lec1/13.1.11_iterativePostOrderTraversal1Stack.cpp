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
        stack <TreeNode*> st;
        TreeNode* curr, *temp; 
        if(root != nullptr) st.push(root), curr = root -> left;
        while(!st.empty()){
            if (curr != nullptr){
                st.push(curr);
                curr = curr -> left;
            }
            else{
                temp = st.top();
                if (temp -> right == nullptr){
                    ans.push_back( temp -> val);
                    st.pop();
                    while(!st.empty() && st.top() -> right == temp ){
                        ans.push_back( st.top() -> val);
                        temp = st.top();
                        st.pop();
                    }
                }
                if (!st.empty()) curr = st.top() -> right;
            }
        }
        return ans;      
    }
};