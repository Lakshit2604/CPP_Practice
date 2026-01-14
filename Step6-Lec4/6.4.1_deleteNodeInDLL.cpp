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
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp = *head_ref;
        while(temp != nullptr){
            if (temp -> data == x){
                Node* del = temp;
                Node *back = temp -> prev;
                Node* front = temp -> next;
                if (temp == *head_ref){
                    *head_ref = (*head_ref) -> next;
                }
                if (back != nullptr) back -> next = front;
                if (front != nullptr) front -> prev = back;
                
                temp = front;
                del -> next = del -> prev = nullptr;
                delete del;
            }
            else temp = temp -> next;
        }
    }
};