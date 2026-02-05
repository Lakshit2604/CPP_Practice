# include <iostream>
# include <stack>
using namespace std;

// Brute
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++){
            int mini = nums[i];
            int maxi = nums[i];
            for (int j = i+1; j < n; j++){
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                sum += maxi - mini;
            }
        }
        return sum;
    }
};

// Optimal
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sumSmall = 0;
        long long sumLarge = 0;
        vector <int> pse(n);
        vector <int> nse(n);
        vector <int> pge(n);
        vector <int> nge(n);
        stack <int> st;
        for (int i = 0; i < n; i++){
            while( !st.empty() && nums[st.top()] > nums[i]) st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for (int i = n-1; i >= 0; i--){
            while( !st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for (int i = 0; i < n; i++){
            while( !st.empty() && nums[st.top()] < nums[i]) st.pop();
            pge[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for (int i = n-1; i >= 0; i--){
            while( !st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nge[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for (int i = 0; i < n; i++){
            sumSmall = sumSmall + (long((i - pse[i]) * (nse[i] - i)) * nums[i]);
            sumLarge = sumLarge + (long((i - pge[i]) * (nge[i] - i)) * nums[i]);
        }
        return sumLarge - sumSmall;
    }
};