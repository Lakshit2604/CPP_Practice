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
    ListNode* cntGroup(ListNode* temp, int k){
        int cnt = 0;
        while (temp != nullptr){
            cnt ++;
            if (cnt == k) return temp;
            temp = temp -> next;
        }
        return nullptr;
    }

    ListNode* reverse(ListNode* head){
        if (head -> next == nullptr) return head;
        ListNode* newHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* t1 = head;
        ListNode* prevhead = nullptr;
        ListNode* nexthead = nullptr;
        while(t1 != nullptr){
            ListNode* kthNode = cntGroup(t1,k);
            if (kthNode == nullptr) return head;
            nexthead = kthNode -> next;
            kthNode -> next = nullptr;
            reverse(t1);
            if (t1 == head) head = kthNode;
            t1 -> next = nexthead;
            if (prevhead != nullptr) prevhead -> next = kthNode;
            prevhead = t1;
            t1 = nexthead;
        }
        return head;
    }
};