# include <iostream>
# include <vector>
# include <stack>
using namespace std;

// Brute
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> nge(n,-1);
        for (int i =0 ; i< n; i++){
            int j = (i+1) % n;
            while (j != i){
                if ( nums[j] > nums[i]){
                    nge[i] = nums[j];
                    break;
                }
                j = (j+1) % n;
            }
        }
        return nge;
    }
};

// Optimal 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack <int> st;
        vector <int> nge(n);
        for (int i = 2*n-1 ; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i%n]) st.pop();
            if ( i < n){
                nge[i] = (st.empty()) ? -1 : st.top(); 
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
}; 