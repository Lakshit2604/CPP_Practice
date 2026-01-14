# include <iostream>
# include <unordered_map>
using namespace std;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Brute
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        unordered_map <Node* , int> mpp;
        Node* temp = head;
        while ( temp != nullptr){
            if (mpp.find(temp) != mpp.end()){
                Node* start = temp;
                int cnt = 0;
                while(temp != nullptr){
                    ++cnt;
                    temp = temp -> next;
                    if (temp == start) return cnt;
                }
            }
            mpp[temp]++;
            temp = temp -> next;
        }
        return 0;
    }
};

// Optimal 
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node *fast = head;
        int cnt = 0;
        while (fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if ( slow == fast ){
                cnt += 1;
                fast = fast -> next;
                while (slow != fast){
                    cnt++;
                    fast = fast -> next;
                }
                return cnt;
            }
        }
        return cnt;
    }
};