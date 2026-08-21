#include <iostream>
# include <sstream>
# include <string>
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string data = "";
        if (root) q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            data.append((front) ? to_string(front->val)+',' : ".,");
            if (front) q.push(front->left);
            if (front) q.push(front->right);
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        queue <TreeNode*> q;
        string str;
        stringstream s (data);
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            getline(s, str, ',');
            if (str != ".") {
                temp -> left = new TreeNode(stoi(str));
                q.push(temp -> left); 
            }

            getline(s, str, ',');
            if (str != "."){
                temp -> right = new TreeNode(stoi(str));
                q.push(temp -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));