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

// Striver's Approach
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        if (root != nullptr) q.push({root, {0,0}});
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                auto top = q.front();
                mpp[top.second.second][top.second.first].insert(top.first->val);
                if ( top.first -> left) q.push({top.first -> left, { top.second.first+1, top.second.second-1}});
                if ( top.first -> right) q.push({top.first -> right, { top.second.first+1, top.second.second+1}});
                q.pop();
            }
        }
        for (auto i : mpp){
            vector<int> temp;
            for (auto j : i.second){
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// My Approach
class Solution {
private:
    void traverse(TreeNode* root, int r, int c, int &minC, unordered_map<int, vector<pair<int,int>>> &mpp){
        if (root == nullptr) return;
        mpp[c].push_back({r,root->val});
        minC = min(minC, c);
        traverse(root->left, r+1, c-1, minC, mpp);
        traverse(root->right, r+1, c+1, minC, mpp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<pair<int,int>>> mpp;
        int minC;
        vector<vector<int>> ans;
        traverse(root,0,0,minC,mpp);
        while (mpp.find(minC) != mpp.end()){
            sort(mpp[minC].begin(), mpp[minC].end());
            vector<int> temp;
            for(auto i : mpp[minC]){
                temp.push_back(i.second);
            }
            ans.push_back(temp);
            minC++;
        }
        return ans;
    }
};
