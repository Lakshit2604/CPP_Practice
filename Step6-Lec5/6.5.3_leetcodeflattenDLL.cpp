# include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* lastNode(Node* head){
        Node* temp = head;
        while(temp -> next != nullptr) temp = temp -> next;
        return temp;
    }

    Node* flatten(Node* head) {
        Node* temp = head;
        while(temp != nullptr){
            if (temp -> child != nullptr){
                Node* newHead = flatten(temp -> child);
                Node* last = lastNode(newHead);
                Node* nextNode = temp -> next;
                last -> next = nextNode;
                newHead -> prev = temp;
                temp -> next = newHead;
                temp -> child = nullptr;
                if (nextNode) nextNode -> prev = last;
                temp = last;
            }
            temp = temp -> next;
        }
        return head;
    }
};