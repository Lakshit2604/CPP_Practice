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

// gfg problem solution : Check if all nodes follow childer sum property or not
class Solution1 {
  public:
    bool isSumProperty(Node *root) {
        if (!root || (!root->left && !root->right)) return true;
        int left = (root->left) ? root->left->data : 0;
        int right = (root->right) ? root->right->data : 0;
        return (root->data == left + right) &&
            isSumProperty(root->left) &&
            isSumProperty(root->right);
    }
};

// Striver problem solution : Make all nodes follow the childer sum property even if they don't, by increment their values.
#include <iostream>
using namespace std;
// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to change the values of the nodes
    // based on the sum of its children's values.
    void changeTree(TreeNode* root){
        if (!root || (!root -> left && !root->right)) return;
        int left = (root->left) ? root->left->val : 0;
        int right = (root->right) ? root->right->val : 0;
        if (root->val > left + right){
          if (root->left) root->left->val = root->val;
          if (root->right) root->right->val = root->val;
        }

        changeTree(root->left);
        changeTree(root->right);
        
        root->val = (root->left) ? root->left->val +  ((root->right) ? root->right->val : 0) : root->right->val ; 
    }
};

// Function to print the inorder
// traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(21); 
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(1);
    // root->right->left = new TreeNode(0);
    // root->right->right = new TreeNode(8);
    // root->left->right->left = new TreeNode(7);
    // root->left->right->right = new TreeNode(4);

    Solution sol;

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    // Call the changeTree function
    // to modify the binary tree
    sol.changeTree(root);

    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;
}
                                            