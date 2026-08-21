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
    int minTime(Node* root, int target) {
        // code here
        unordered_map <Node*, Node*> mpp;
        queue<Node*> q;
        if (root) q.push(root);
        Node* targetNode;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                Node* top = q.front();
                q.pop();
                if (top->data == target) targetNode = top;
                if (top->left){
                    q.push(top->left);
                    mpp[top->left] = top;
                }
                if (top->right){
                    q.push(top->right);
                    mpp[top->right] = top;
                }
            }
        }
        unordered_map<Node*, int> visited;
        queue <pair<Node*, int>> que;
        if (targetNode) que.push({targetNode, 0});
        int maxTime = 0;
        while(!que.empty()){
            auto top = que.front();
            que.pop();
            visited[top.first] = 1;
            maxTime = top.second;
            if (top.first->left && (visited.find(top.first->left) == visited.end())) que.push({top.first->left, top.second+1});
            if (top.first->right && (visited.find(top.first->right) == visited.end())) que.push({top.first->right, top.second+1});
            if (mpp.find(top.first) != mpp.end() && (visited.find(mpp[top.first]) == visited.end())) que.push({mpp[top.first], top.second+1});
        }
        return maxTime;
    }
};