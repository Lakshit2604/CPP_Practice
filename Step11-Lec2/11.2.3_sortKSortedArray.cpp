# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int pos = 0;
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin()+k);
        for (int i = k; i < n; i++){
            pq.push(arr[i]);
            arr[pos++] = pq.top();
            pq.pop();
        }
        while (!pq.empty()){
            arr[pos++] = pq.top();
            pq.pop();
        }
    }
};