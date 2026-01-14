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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        unordered_map< ListNode*, int > mpp;
        ListNode *temp = head;
        while(temp != nullptr){
            if (mpp.find(temp) != mpp.end()) return true;
            mpp[temp]++;
            temp = temp -> next;
        }
        return false;
    }
};

// Optimal
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow-> next;
            fast = fast -> next -> next;
            if (slow == fast) return true;
        }
        return false;
    }
};