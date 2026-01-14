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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return nullptr;
        int cnt = 0;
        ListNode *temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp -> next;
        }
        temp = head;
        int mid = cnt/2;
        while(mid != 1){
            mid--;
            temp = temp -> next;
        }
        ListNode *del = temp -> next;
        temp -> next = del -> next;
        delete del;
        return head;
    }
};

// Optimal
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return nullptr;
        ListNode* slow = head, *fast = head, *prev;
        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = slow -> next;
        slow -> next = nullptr;
        delete slow;
        return head;
    }
};