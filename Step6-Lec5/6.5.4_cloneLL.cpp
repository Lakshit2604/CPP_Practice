# include <iostream>
# include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Brute
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        map <Node* , Node*> mpp;
        while(temp != nullptr){
            mpp[temp] = new Node (temp -> val);
            temp = temp -> next;
        }
        temp = head;
        while(temp != nullptr){
            if (temp -> next == nullptr) mpp[temp] -> next = nullptr;
            else mpp[temp] -> next = mpp[temp-> next];
            if (temp -> random == nullptr) mpp[temp] -> random = nullptr; 
            else mpp[temp] -> random = mpp[temp -> random];
            temp = temp -> next;
        }
        return mpp[head];
    }
};

// Optimal 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp != nullptr){
            Node* copy = new Node (temp -> val);
            copy -> next = temp -> next;
            temp -> next = copy;
            temp = copy -> next;
        }
        temp = head;
        while(temp != nullptr){
            Node* copy = temp -> next;
            if (temp -> random != nullptr) copy -> random = temp -> random -> next;
            temp = copy -> next;
        }
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        temp = head;
        while(temp != nullptr){
            curr -> next = temp -> next;
            curr = curr -> next;
            temp -> next = curr -> next;
            if (curr -> next != nullptr) curr -> next = curr -> next -> next;
            temp = temp -> next;
        }
        return dummy -> next;
    }
};