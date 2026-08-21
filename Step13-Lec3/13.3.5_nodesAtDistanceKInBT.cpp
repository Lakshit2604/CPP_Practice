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

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*, TreeNode*> mpp;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* top = q.front();
                q.pop();
                if (top->left){
                    q.push(top->left);
                    mpp[top->left] = top;
                }
                if (top->right){
                    q.push(top->right);
                    mpp[top->right] = top;
                }
            }
        }
        vector <int> ans;
        unordered_map<TreeNode*, int> visited;
        queue <pair<TreeNode*, int>> que;
        if (target) que.push({target, 0});
        while(!que.empty()){
            auto top = que.front();
            que.pop();
            visited[top.first] = 1;
            if (top.second == k) {
                ans.push_back(top.first->val);
                continue;
            }
            if (top.first->left && (visited.find(top.first->left) == visited.end())) que.push({top.first->left, top.second+1});
            if (top.first->right && (visited.find(top.first->right) == visited.end())) que.push({top.first->right, top.second+1});
            if (mpp.find(top.first) != mpp.end() && (visited.find(mpp[top.first]) == visited.end())) que.push({mpp[top.first], top.second+1});
        }
        return ans;
    }
};