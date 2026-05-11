# include <iostream>
# include <vector>
# include <queue>
using namespace std;

// Brute
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n-k];
    }
};

// Optimal 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue <int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);
        for ( int i = k; i < n; i++){
            if (pq.top() < nums[i]){
                pq.push(nums[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};