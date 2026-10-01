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

// Optimal
class Solution {
  private:
    Node* successor(Node* root, int key, Node* succ){
        if ( !root ) return succ;
        if (root -> data > key){
            succ = root;
            return successor(root -> left, key, succ);
        }
        return successor(root -> right, key, succ);
        
    }
    
    Node* predecessor(Node* root, int key, Node* pred){
        if ( !root ) return pred;
        if ( root -> data < key){
            pred = root;
            return predecessor(root -> right, key, pred);
        }
        return predecessor(root -> left, key, pred);
    }
    
  public:
    vector<Node*> findPreSuc(Node* root, int key){
        return {predecessor(root, key, nullptr), successor(root, key, nullptr)};
    }
};