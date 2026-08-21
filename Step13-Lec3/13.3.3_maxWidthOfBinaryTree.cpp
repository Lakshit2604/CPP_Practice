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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root) q.push({root, 0});
        long maxWidth = 0;
        while(!q.empty()){
            int size = q.size();
            long minCol = q.front().second;
            long col, newCol; 
            for (int i = 0; i < size; i++){
                TreeNode* top = q.front().first;
                col = q.front().second;
                q.pop();
                newCol = (col - minCol);
                if (top->left) q.push({top->left, 2*newCol +1});
                if (top->right) q.push({top->right, 2*newCol +2});
            }
            maxWidth = (max(maxWidth, newCol + 1));
            cout << minCol << ' ' << col << ' ' << maxWidth << '\n';
        }
        return maxWidth;
    }
};