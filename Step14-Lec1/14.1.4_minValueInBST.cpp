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
  public:
    int minValue(Node* root) {
        // code here
        if (root == nullptr) return -1;
        if (!root->left) return root->data;
        return minValue(root->left);
    }
};