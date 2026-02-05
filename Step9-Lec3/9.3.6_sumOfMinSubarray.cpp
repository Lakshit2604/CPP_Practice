# include <iostream>
# include <vector>
using namespace std;

// Brute 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++){
            int mini = arr[i];
            for (int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                sum = (sum + mini) % (1000000007);
            }
        }
        return sum;
    }
};

// Optimal
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = 1e9 + 7;
        vector<int> nse(n);
        vector<int> pse(n);
        stack <int> st;
        for (int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i); 
        }
        while(!st.empty()) st.pop();
        for (int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i); 
        }
        for (int i =0; i < n; i++){
            long freq = (i - pse[i]) * (nse[i] - i) * long(arr[i]);
            sum = (sum + freq) % mod;
        }
        return sum;
    }
};
