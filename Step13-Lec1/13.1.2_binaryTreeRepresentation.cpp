# include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  private:
    Node* solve(vector<int>& nodes, int i, int n){
        Node* root = new Node(nodes[i]);
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n) {
            root -> left = solve(nodes, left, n);
        }
        if (right < n){ 
            root -> right = solve(nodes, right, n);   
        }
        return root;
    }
    
  public:
    Node* buildTree(vector<int>& nodes) {
        // code here
        int n = nodes.size();
        return solve(nodes, 0, n);
    }
};

