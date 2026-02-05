# include <iostream>
# include <stack>
# include <vector>
using namespace std;

// Brute
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        stack <int> st;
        vector<int> pse(n);
        vector<int> nse(n);
        for (int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n-1; i >= 0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++){
            maxi = max(maxi, (nse[i] - pse[i] - 1)*heights[i]);
        }
        return maxi;
    }
};

// Optimal 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        stack <int> st;
        for (int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int curr = st.top();
                st.pop();
                int pse = (st.empty()) ? -1 : st.top();
                maxi = max(maxi, (i - pse - 1) * heights[curr]);
            }
            st.push(i);
        }
        while (!st.empty()){
            int curr = st.top();
            st.pop();
            int pse = (st.empty()) ? -1 : st.top();
            maxi = max(maxi, (n - pse - 1) * heights[curr]);
        }
        return maxi;
    }
};