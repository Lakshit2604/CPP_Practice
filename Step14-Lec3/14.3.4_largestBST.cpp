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

class Info{
public:
    int size;
    int maxi;
    int mini;
    
    Info (int s, int mx, int mn) : size(s), maxi(mx), mini(mn) {};
};


class Solution {
  private:
    Info solve(Node* root){
        if (!root){
            return Info(0, INT_MIN, INT_MAX);
        }
        Info l = solve(root -> left);
        Info r = solve(root -> right);
        // cout << root -> data << ' '; 
        // cout << l.size << ' ' << l.maxi << ' ' << l.mini << '\n';
        // cout << r.size << ' ' << r.maxi << ' ' << r.mini << "\n\n";
        if (l.maxi < root -> data  && root -> data < r.mini){
            // cout << l.maxi << ' ' << root -> data << ' ' << r.mini << '\n';
            return Info (
                l.size + r.size + 1, 
                max(r.maxi, root -> data),
                min(l.mini, root -> data)
            );
        }
        return Info (
            max(l.size, r.size), 
            INT_MAX, 
            INT_MIN
        );
        
    }
    
  public:
    int largestBst(Node *root) {
        // code here
        return solve(root).size;
    }
};