# include <iostream>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> q;
        vector<vector<int>> ans;
        if (root != nullptr) q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector <int> level;
            for (int i = 0; i < size; i++){
                TreeNode* top = q.front();
                level.push_back(top -> val);
                if (top -> left != nullptr) q.push(top -> left);
                if (top -> right != nullptr) q.push(top -> right);
                q.pop();
            }
            ans.push_back(level);
        }
        return ans;
    }
};