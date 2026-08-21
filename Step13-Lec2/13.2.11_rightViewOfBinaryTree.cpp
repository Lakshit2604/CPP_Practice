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

// Level Order Traversal
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mpp;
        queue <pair<TreeNode*, int>> q;
        vector<int> ans;
        if (root != nullptr){
            q.push({root, 0});
        }
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* top = q.front().first;
                int row = q.front().second;
                // cout << top -> data << ' ' << "row:" << row << ' ' << "col:" << col << '\n';
                q.pop();
                mpp[row] = top->val;
                if (top -> left) q.push({top->left, row+1});
                if (top -> right) q.push({top->right, row+1});
            }
        }
        for (auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;   
    }
};

// recursion
class Solution {
private:
    void traverse(TreeNode* root, int row, map<int, int> &mpp){
        if (root == nullptr) return;
        if (mpp.find(row) == mpp.end()) mpp[row] = root->val;
        traverse(root -> right, row+1, mpp);
        traverse(root -> left, row+1, mpp);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mpp;
        vector<int> ans;
        traverse(root,0, mpp);
        for (auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;   
    }
};