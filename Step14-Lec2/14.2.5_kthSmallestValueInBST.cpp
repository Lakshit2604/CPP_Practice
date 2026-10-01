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

class Solution {
private:
    bool solve(TreeNode* root, int k , priority_queue<int> &pq){
        if ( !root ) return true;
        if (pq.size() >= k){
            if (root -> val > pq.top()) return false;
            pq.push(root -> val);
            pq.pop();
        } 
        else pq.push(root -> val);
        return solve(root -> left, k, pq) && solve(root -> right, k, pq);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
       priority_queue<int> pq;
       solve(root, k, pq);
       return pq.top();
    }   
};