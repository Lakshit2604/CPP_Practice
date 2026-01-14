# include <iostream>
# include <vector>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Brute
class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        head = reverse(head);
        Node* temp = head;
        int carry = 1;
        while( temp != nullptr){
            if (carry) temp -> data = temp -> data + carry, carry = 0;
            else break;
            if (temp -> data == 10){
                carry = 1;
                temp -> data = 0;
            }
            temp = temp -> next;
        }
        head = reverse(head);
        if (carry){
            Node* newHead = new Node(1);
            newHead -> next = head;
            return newHead;
        }
        return head;
    }
    
    Node* reverse(Node* head){
        if (head -> next == nullptr) return head;
        Node* newHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return newHead;
    }
};

// Optimal 
class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        int carry = carryCount(head);
        if (carry) {
            Node* newHead = new Node(1);
            newHead -> next = head;
            return newHead;
        }
        return head;
    }
    
    int carryCount(Node* head){
        if (head == nullptr) return 1;
        int carry = carryCount(head->next);
        head -> data = head -> data + carry;
        carry = 0;
        if (head -> data == 10){
            head -> data = 0;
            return 1;
        }
        return 0;
    }
};