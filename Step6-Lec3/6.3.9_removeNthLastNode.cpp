# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Brute
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head -> next == nullptr) return nullptr;
        int cnt = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            cnt++;
            temp = temp -> next;
        }
        int rem = cnt - n;
        temp = head;
        if (rem == 0){
            head = head -> next;
            temp -> next = nullptr;
            delete temp;
            return head;
        }
        while ( temp != nullptr){
            rem--;
            if (rem == 0){
                ListNode* x = temp-> next;
                temp -> next = x-> next;
                x -> next = nullptr;
                delete x;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
};

// Optimal 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head ;
        ListNode* slow = head;
        for (int i = 0; i < n ; i++){
            fast = fast -> next;
        }
        if (fast == nullptr){
            head = head -> next;
            slow -> next = nullptr; 
            delete slow;
            return head;
        }

        while(fast -> next != nullptr){
            slow = slow -> next ;
            fast = fast -> next;
        }

        ListNode * del = slow -> next;
        slow -> next = del -> next;
        del -> next = nullptr;
        delete del;
        return head;
    }
};