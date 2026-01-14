# include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        if (root -> next == nullptr) return root;
        Node* merge = flatten(root -> next);
        return mergeNodes(root, merge);
    }
    
    Node* mergeNodes(Node* t1, Node* t2 ){
        Node* dummy = new Node (-1);
        Node* curr = dummy;
        while (t1 != nullptr && t2 != nullptr){
            if (t1 -> data < t2 -> data){
                curr -> bottom = new Node(t1 -> data);
                t1 = t1 -> bottom;
            }
            else {
                curr -> bottom = new Node (t2 -> data);
                t2 = t2 -> bottom;
            }
            curr = curr -> bottom;
        }
        while (t1 != nullptr){
            curr -> bottom = new Node (t1 -> data);
            t1 = t1 -> bottom;
            curr = curr -> bottom;
        }
        
        while ( t2 != nullptr){
            curr -> bottom = new Node (t2 -> data);
            t2 = t2 -> bottom;
            curr = curr -> bottom;
        }
        return dummy -> bottom;
    }
};