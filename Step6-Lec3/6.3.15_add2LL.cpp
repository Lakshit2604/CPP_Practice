# include <iostream>
# include <map>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* t3 = dummy; 
        int carry = 0;
        while(t1 != nullptr || t2 != nullptr){
            int sum  = 0;
            if(t1) sum += t1 -> val, t1 = t1 -> next;
            if(t2) sum += t2 -> val, t2 = t2 -> next;
            sum += carry;
            t3 -> next = new ListNode(sum % 10);
            carry = sum / 10;
            t3 = t3 -> next;
        }   
        if (carry) {
            t3 -> next = new ListNode(carry);
        }
        return dummy -> next;
    }
};