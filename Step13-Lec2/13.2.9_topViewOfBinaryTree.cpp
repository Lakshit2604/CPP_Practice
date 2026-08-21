#include <iostream>
#include <map>
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
    vector<int> topView(Node *root) {
        map<int, int> mpp;
        queue <pair<Node*, pair<int, int>>> q;
        vector<int> ans;
        if (root != nullptr){
            q.push({root,{0,0}});
        }
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                Node* top = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                // cout << top -> data << ' ' << "row:" << row << ' ' << "col:" << col << '\n';
                q.pop();
                if(mpp.find(col) == mpp.end()) mpp[col] = top->data;
                if (top -> left) q.push({top->left, {row+1, col-1}});
                if (top -> right) q.push({top->right, {row+1, col+1}});
            }
        }
        for (auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;
    }
};