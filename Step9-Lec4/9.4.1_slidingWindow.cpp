# include <iostream>
# include <stack>
using namespace std;

// Brute
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans;
        for (int i = 0; i <= n-k; i++){
            int win = k;
            int maxi = INT_MIN;
            while (win--){
                maxi = max(maxi , nums[i+win]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

// Optimal
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector <int> ans;
        for (int i = 0; i < n; i++){
            if ( !dq.empty() && (i - dq.front())>= k ) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if ( i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};