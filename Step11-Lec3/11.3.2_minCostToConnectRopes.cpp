# include <iostream>
# include <queue>
# include <vector>
using namespace std;
// Brute
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int sum = 0;
        while(arr.size() != 1){
            sort(arr.begin(), arr.end());
            int total = arr[0] + arr[1];
            arr.erase(arr.begin(), arr.begin() + 2);
            arr.push_back(total);
            sum += total;
        }
        return sum;
    }
};

// Optimal
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : arr) {
            pq.push(i);
        }
        while(pq.size() != 1){
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            int total = top1 + top2;
            pq.push(total);
            sum += total;
        }
        return sum ;
    }
};