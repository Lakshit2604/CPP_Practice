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
    int leftTraversal(Node* root, vector<int> &arr, bool &flag){
        if (root == nullptr) return 0;
        if (!flag) arr.push_back(root -> data);
        int left = leftTraversal(root->left, arr, flag);
        if (left == 0) {
            int right = leftTraversal(root->right, arr, flag);
            if (right == 0) arr.pop_back(), flag = 1;
        }
        return root -> data;
    }
    
    int leaf(Node* root, vector<int> &arr){
        if (root == nullptr) return 0;
        int left = leaf(root->left, arr);
        int right = leaf(root->right, arr);
        if (left == 0 && right == 0){
            arr.push_back(root -> data);
        }
        return root -> data;
    }
    
    int rightTraversal(Node* root, vector<int> &arr){
        if (root == nullptr) return 0;
        int right = rightTraversal(root->right, arr);
        if (right == 0){
            int left = rightTraversal(root->left, arr);
            if (left == 0) return root->data;
        }
        arr.push_back(root->data);
        return root->data;
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> arr;
        bool flag = 0;
        if (root -> left != nullptr || root -> right != nullptr){
            arr.push_back(root -> data);
        }
        leftTraversal(root->left, arr, flag);
        leaf(root, arr);
        rightTraversal(root->right, arr);
        return arr;
    }
};