#include <iostream>
using namespace std;

// Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  private:
    int preorder(Node* root, vector<int> &route, vector<vector<int>> &ans){
        if (root == nullptr) return 0;
        route.push_back(root->data);
        int left = preorder(root->left, route, ans);
        int right = preorder(root->right, route, ans);
        if (left == 0 && right == 0){
            ans.push_back(route);
        }
        route.pop_back();
        return root->data;
    }
  public:
    vector<vector<int>> paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> route;
        preorder(root, route, ans);
        return ans;
    }
};