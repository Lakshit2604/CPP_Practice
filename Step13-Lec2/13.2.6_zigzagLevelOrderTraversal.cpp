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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        queue <TreeNode*> q;
        if (root) q.push(root);
        bool flag = 0;
        while (!q.empty()){
            vector<int> level ;
            int len = q.size();
            flag = !flag;
            for (int i = 0; i < len; i++){
                TreeNode* front = q.front();
                level.push_back(front->val);
                if (front -> left) q.push(front->left); 
                if (front -> right) q.push(front->right); 
                q.pop();
            }
            if (!flag) reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        return ans;
    }
};