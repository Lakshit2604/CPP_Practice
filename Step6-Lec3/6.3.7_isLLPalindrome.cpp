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
    bool isPalindrome(ListNode* head) {
        if ( head -> next == nullptr) return true;
        stack <int> st; 
        ListNode *temp = head;
        while(temp != nullptr){
            st.push(temp->val);
            temp = temp -> next;
        }
        temp = head;
        while(temp != nullptr){
            if (temp -> val == st.top()){
                st.pop();
                temp = temp -> next;
            }
            else return false;
        }
        return true;
    }
};

// Optimal
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head -> next == nullptr) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast ->next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *head1 = reverseLL(slow -> next);
        ListNode *temp1 = head;
        ListNode * temp2 = head1;
        while(temp2 != nullptr){
            if (temp1 -> val != temp2 -> val){
                head1 = reverseLL(head1);
                return false;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        head1 = reverseLL(head1);
        return true;
    }

    ListNode *reverseLL(ListNode *head){
        if (head -> next == nullptr) return head;
        ListNode *newHead = reverseLL(head->next);
        head -> next -> next = head;
        head -> next = nullptr;
        return newHead;
    }
};