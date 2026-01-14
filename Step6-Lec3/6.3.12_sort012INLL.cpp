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
    Node* segregate(Node* head) {
        // code here
        Node* temp = head;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        while(temp != nullptr){
            if (temp -> data == 0) cnt0++;
            if (temp -> data == 1) cnt1++;
            if (temp -> data == 2) cnt2++;
            temp = temp -> next;
        }
        temp = head;
        while(temp != nullptr){
            if (cnt0 != 0){
                temp -> data = 0;
                cnt0--;
            }
            else if (cnt1 != 0){
                temp -> data = 1;
                cnt1--;
            }
            else {
                temp -> data = 2;
                cnt2--;
            }
            temp = temp -> next;
        }
        return head;
    }
};

// Opitmal
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node *ll0Head = new Node(-1); 
        Node *ll0Temp = ll0Head;
        Node *ll1Head = new Node(-1);
        Node *ll1Temp = ll1Head;
        Node *ll2Head = new Node(-1);
        Node *ll2Temp = ll2Head;
        Node *temp = head;
        while (temp != nullptr ){
            if (temp -> data == 0){
                ll0Temp -> next = temp;
                temp = temp -> next;
                ll0Temp = ll0Temp -> next;
                ll0Temp -> next = nullptr;
            }
            else if (temp -> data == 1){
                ll1Temp -> next = temp;
                temp = temp -> next;
                ll1Temp = ll1Temp -> next;
                ll1Temp -> next = nullptr;
            }
            else {
                ll2Temp -> next = temp;
                temp = temp -> next;
                ll2Temp = ll2Temp -> next;
                ll2Temp -> next = nullptr;
            }
        }
        
        if (ll1Head -> next == nullptr){
            ll0Temp -> next = ll2Head -> next;
            return ll0Head -> next;
        }
        
        ll0Temp -> next = ll1Head -> next;
        ll1Temp -> next = ll2Head -> next;
        return ll0Head -> next;
    }
};