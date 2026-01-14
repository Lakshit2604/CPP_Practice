# include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Approach - 1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* tail = head;
        int cnt = 0;
        while(tail != nullptr) cnt++, tail = tail->next;
        ListNode* temp = head;
        int mid = cnt/2;
        while(mid--) temp = temp -> next;
        return temp;
    }
};

// Optimal
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while( fast != nullptr && fast->next != nullptr ){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};