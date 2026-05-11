# include <iostream>
# include <vector>
# include <queue>
using namespace std;

// Brute
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};

// Optimal
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int> pq(arr.begin(), arr.begin()+k);
        for (int i = k; i < n ; i++){
            pq.push(arr[i]);
            pq.pop();
        }
        return pq.top();
    }
};