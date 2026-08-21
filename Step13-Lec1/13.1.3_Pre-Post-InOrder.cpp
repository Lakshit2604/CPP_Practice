# include <iostream>
# include <vector>
# include <stack>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    vector<vector<int>> preInPostTraversal(Node* root) {
        vector<int> pre, in, post;
        stack <pair<Node*, int>> st;
        st.push({root, 1});
        while (!st.empty()){
            auto &top = st.top();
            if ( top.second == 1){
                pre.push_back(top.first -> val);
                top.second++;
                if (top.first -> left != nullptr) st.push({top.first -> left, 1});
            }
            else if ( top.second == 2){
                in.push_back(top.first -> val);
                top.second++;
                if (top.first -> right != nullptr) st.push({top.first -> right, 1});
            }
            else if (top.second == 3){
                post.push_back(top.first -> val);
                st.pop();
            }
        }
        return {pre, in, post};
    }
};
int main(){
    Node* root = new Node(1);
    root -> left = new Node(3);
    root -> right = new Node(4);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(2);
    root -> right -> left = new Node(7);
    root -> right -> right = new Node(6);

    Solution sol;
    vector<vector<int>> all = sol.preInPostTraversal(root);
    vector<int> pre = all[0], in = all[1], post = all[2];
    for (int i : pre) cout << i << ' ';
    cout << '\n';
    for (int i : in) cout << i << ' ';
    cout << '\n';
    for (int i : post) cout << i << ' ';
    cout << '\n';
    return 0;
}