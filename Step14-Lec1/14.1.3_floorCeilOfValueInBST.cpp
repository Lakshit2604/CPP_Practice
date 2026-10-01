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

// ceil
class Solution {
  public:
    int ceil = -1;
    int findCeil(Node* root, int x) {
        // code here
        if (!root) return ceil;
        if (root->data == x) return x;
        if (root->data > x) {
            ceil = root->data;
            return findCeil(root->left, x);
        }
        return findCeil(root->right, x);
    }
};

// floor
class Solution {
  public:
    int floor = -1;
    int findMaxFork(Node* root, int k) {
        // code here
        if (!root) return floor;
        if (root->data == k) return k;
        if (root->data > k) return findMaxFork(root->left,k);
        floor = root->data;
        return findMaxFork(root->right,k);
    }
};