# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode* tail = head;
        int cnt = 1;
        while (tail -> next != nullptr){
            cnt++;
            tail = tail -> next;
        }
        k = k % cnt;
        if (k == 0) return head;
        ListNode* temp = head;
        ListNode* newHead = nullptr;
        int rem = cnt - k;
        while (temp != nullptr){
            rem--;
            if (rem == 0) {
                newHead = temp -> next;
                temp -> next = nullptr;
                tail -> next = head;
                break;
            }
            temp = temp -> next;
        }
        return newHead;
    }
};