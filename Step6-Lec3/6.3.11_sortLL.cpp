# include <iostream>
# include <vector>
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
    ListNode* sortList(ListNode* head) {
        vector <int> arr;
        ListNode *temp = head;
        while(temp != nullptr){
            arr.push_back(temp -> val);
        }
        sort(arr.begin(), arr.end());
        temp = head;
        int i = 0;
        while(temp != nullptr){
            temp -> val = arr[i];
            i++;
            temp = temp -> next;
        }
        return head;
    }
};

// Optimal
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode* mid = findMid(head);
        ListNode* rightHead = mid -> next;
        ListNode* leftHead = head;
        mid -> next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return merge(leftHead, rightHead);
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* merge(ListNode* leftHead, ListNode* rightHead){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(leftHead != nullptr && rightHead != nullptr){
            if (leftHead -> val < rightHead -> val){
                temp -> next = leftHead;
                leftHead = leftHead -> next;
                temp = temp -> next;
            }
            else {
                temp -> next = rightHead;
                rightHead = rightHead -> next;
                temp = temp -> next;
            }
            if (leftHead != nullptr){
                temp -> next = leftHead;
            }
            else temp -> next = rightHead;
        }
        return dummy -> next;
    }
};