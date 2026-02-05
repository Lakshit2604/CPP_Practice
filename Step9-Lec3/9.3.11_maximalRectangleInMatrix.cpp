# include <iostream>
# include <stack>
# include <vector>
using namespace std;

// Optimal 
class Solution {
private:
    int largestHisto(vector<int> heights){
        stack <int> st;
        int maxi = 0;
        int n = heights.size();
        for (int i = 0 ; i < n; i++){
            while(!st.empty() && (heights[st.top()] >= heights[i])){
                int curr = st.top();
                st.pop();
                int psi = (st.empty()) ? -1 : st.top();
                maxi = max(maxi, (i - psi - 1)*(heights[curr]));
            }
            st.push(i);
        }
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            int psi = (st.empty()) ? -1 : st.top();
            maxi = max(maxi, (n - psi - 1)*(heights[curr]));
        }
        return maxi;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pre(n, vector<int> (m));
        int maxi = 0;
        for (int j = 0; j < m; j++){
            int sum = 0;
            for (int i = 0; i < n; i++){
                if (matrix[i][j] == '0') sum = 0;
                sum += (matrix[i][j] - '0');
                pre[i][j] = sum ;
            }
        }
        for (int i = 0; i < n; i++){
            maxi = max(maxi, largestHisto(pre[i]));
        }
        return maxi;
    }
};

// Slightly optimised Space 
class Solution {
private:
    int largestHisto(vector<int> heights){
        stack <int> st;
        int maxi = 0;
        int n = heights.size();
        for (int i = 0 ; i < n; i++){
            while(!st.empty() && (heights[st.top()] >= heights[i])){
                int curr = st.top();
                st.pop();
                int psi = (st.empty()) ? -1 : st.top();
                maxi = max(maxi, (i - psi - 1)*(heights[curr]));
            }
            st.push(i);
        }
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            int psi = (st.empty()) ? -1 : st.top();
            maxi = max(maxi, (n - psi - 1)*(heights[curr]));
        }
        return maxi;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> pre(m);
        int maxi = 0;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == '0') sum = 0;
                else sum = (matrix[i][j] - '0') + pre[j];
                pre[j] = sum ;
            }
            maxi = max(maxi, largestHisto(pre));
        }
        return maxi;
    }
};