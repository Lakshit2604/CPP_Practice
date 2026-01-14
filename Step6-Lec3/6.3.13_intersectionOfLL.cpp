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

// Brute
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode* temp2 = headB;
        map <ListNode*, int> mpp;
        while(temp1 != nullptr){
            mpp[temp1] = 1;
            temp1 = temp1 -> next;
        }
        while (temp2 != nullptr){
            if(mpp.find(temp2) != mpp.end()) return temp2;
            temp2 = temp2 -> next;
        }
        return nullptr;
    }
};

// Better
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode* temp2 = headB;
        int cnt1 = 0, cnt2 = 0;
        while(temp1 != nullptr || temp2 != nullptr){
            if (temp1) cnt1++ , temp1 = temp1 -> next;
            if (temp2) cnt2++ , temp2 = temp2 -> next;  
        }
        int diff = abs(cnt1 - cnt2);
        temp1 = headA;
        temp2 = headB;
        for (int i = 0; i < diff; i++){
            if (cnt1 > cnt2){
                temp1 = temp1 -> next;   
            }
            else {
                temp2 = temp2 -> next;
            }
        }
        while(temp1 != temp2){
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return temp1;
    }
};

// Optimal
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1 != temp2){
            if (temp1) temp1 = temp1 -> next;
            else temp1 = headB;
            if (temp2) temp2 = temp2 -> next;  
            else temp2 = headA;
        }
        return temp1;
    }
};