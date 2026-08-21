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

// Brute
class Solution {
private:
    bool routeToLeaf(TreeNode* root, TreeNode* p, vector<TreeNode*> &route){
        if (root == nullptr) return false;
        route.push_back(root);
        if (root -> val == p -> val) return true;
        if(routeToLeaf(root->left,p,route) || routeToLeaf(root->right,p,route)) return true;
        route.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> routeP, routeQ;
        routeToLeaf(root,p,routeP);
        routeToLeaf(root,q,routeQ);
        int maxi = max(routeP.size(), routeQ.size());
        TreeNode* ans = nullptr;
        for (int i = 0; i < maxi; i++){
            if ( i >= routeP.size() || i >= routeQ.size()) break;
            if (routeP[i] != routeQ[i]) break;
            ans = routeP[i];
        }
        return ans;
    }  
};

// Optimal
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root -> left,p,q);
        TreeNode* right = lowestCommonAncestor(root -> right,p,q);
        if (left == nullptr) return right;
        else if (right == nullptr) return left;
        return root;
    }  
};