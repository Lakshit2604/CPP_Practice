# include <iostream>
# include <unordered_map>
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        unordered_map <ListNode*, int> mpp;
        ListNode *temp = head;
        while(temp != nullptr){
            if (mpp.find(temp) != mpp.end()) return temp;
            mpp[temp]++;
            temp = temp -> next;
        }
        return nullptr;
    }
};

// Optimal
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast-> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};