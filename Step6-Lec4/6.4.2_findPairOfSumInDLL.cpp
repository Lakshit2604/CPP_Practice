# include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

// Brute
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> arr ;
        Node* t1 = head;
        while(t1 != nullptr){
            Node* t2 = t1 -> next;
            while(t2 != nullptr){
                if (t1 -> data + t2 -> data == target){
                    arr.emplace_back(t1-> data , t2 -> data);
                }
                t2 = t2 -> next;
            }
            t1 = t1 -> next;
        }
        return arr;
    }
};

// Optimal
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> arr ;
        Node* t1 = head;
        Node* t2 = head;
        while(t2 -> next != nullptr){
            t2 = t2 -> next;
        }
        while(t1 != t2 && t1 -> prev != t2 ){
            int sum = t1 -> data + t2 -> data;
            if (sum == target) {
                arr.emplace_back(t1->data, t2-> data);
                t1 = t1 -> next;
                t2 = t2 -> prev;
            }
            else if (sum > target) t2 = t2 -> prev;
            else t1 = t1 -> next;
        }
        return arr;
    }
};