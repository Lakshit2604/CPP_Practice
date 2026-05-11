# include <iostream>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <int> arr;
        int n = lists.size();
        for (int i = 0; i < n; i++){
            ListNode* t = lists[i];
            while (t != nullptr){
                arr.push_back(t -> val);
                t = t -> next;
            }
        }
        sort (arr.begin(), arr.end());
        ListNode* ans = new ListNode (-1);
        ListNode* t = ans;
        for (int i = 0; i < arr.size(); i++){
            t -> next = new ListNode(arr[i]);
            t = t -> next;
        }
        return ans -> next;
    }
};

// Better
class Solution {
private:
    ListNode* merge2Lists(ListNode *t1, ListNode *t2){
        ListNode* dummy = new ListNode(-1);
        ListNode* d = dummy;
        while (t1 != nullptr && t2 != nullptr){
            if ((t1 -> val) <= (t2 -> val)) {
                d -> next = t1;
                d = d -> next;
                t1 = t1 -> next; 
            }
            else {
                d -> next = t2;
                d = d-> next;
                t2 = t2 -> next;
            }
        }
        if ( t1 != nullptr) d -> next = t1;
        if (t2 != nullptr) d -> next = t2;
        return dummy -> next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <int> arr;
        int n = lists.size();
        if (n == 0 ) return nullptr;
        if (n == 1) return lists[0];
        ListNode *t1, *t2;
        t1 = lists[0];
        for (int i = 1; i < n; i++){
            t2 = lists[i];
            t1 = merge2Lists(t1,t2);
        }
        return t1;
    }
};

// Optimal
// pq <template, container, comparator>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue <pair<int, ListNode*>,vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (int i = 0; i< n; i++){
            if (lists[i]){
                ListNode* temp = lists[i];
                pq.push({temp->val, temp});
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* d = dummy;
        while(!pq.empty()){
            ListNode* t = pq.top().second;
            d -> next = t;
            d = d -> next;
            t = t -> next;
            pq.pop();
            if ( t != nullptr) pq.push({t -> val, t});
        }
        return dummy -> next;
    }
};