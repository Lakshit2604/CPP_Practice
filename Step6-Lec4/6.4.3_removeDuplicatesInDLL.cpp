# include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* t1 = head->next;
        Node* back = head;
        while(t1 != nullptr){
            if (t1 -> data == back -> data){
                Node* dup = t1;
                t1 = t1 -> next;
                dup -> next = dup -> prev = nullptr;
                delete dup;
            }
            else {
                back -> next = t1;
                t1 -> prev = back;
                back = t1;
                t1 = t1 -> next;
            }
        }
        back -> next = nullptr;
        return head;
    }
};