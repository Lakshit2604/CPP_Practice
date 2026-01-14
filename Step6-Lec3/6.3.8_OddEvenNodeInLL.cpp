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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode* temp = head;
        vector <int> arr;
        while(temp -> next != nullptr && temp -> next -> next != nullptr){
            arr.push_back(temp -> val);
            temp = temp -> next -> next;
        }
        arr.push_back(temp -> val);

        temp = head-> next;
        while(temp -> next!= nullptr && temp -> next -> next  != nullptr){
            arr.push_back(temp -> val);
            temp = temp -> next -> next;
        }
        arr.push_back(temp -> val);

        temp =  head;
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode * head1 = head -> next;
        ListNode* odd = head;
        ListNode* even = head -> next;
        while(odd -> next != nullptr && odd -> next -> next != nullptr){
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = head1;
        return head;
    }
};