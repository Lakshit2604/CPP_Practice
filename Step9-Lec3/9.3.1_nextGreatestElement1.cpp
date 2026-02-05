# include <iostream>
# include <vector>
# include <stack>
using namespace std;

// Brute - TC : O(n1*n2) ; SC - O(n1)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nge;
        for ( int i = 0; i < n1; i++){
            bool match = false;
            for (int j = 0; j < n2 ; j++){
                if (match && nums2[j] > nums1[i]){
                    nge.push_back(nums2[j]);
                    break;
                }
                if (nums1[i] == nums2[j]) match = true;
            }
            if (nge.size() < i+1) nge.push_back(-1);
        }
        return nge;
    }
};

// Optimal - TC : O(2*n2 + n2 + n1) ; SC - O(n2 + n2 + n1)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nge;
        unordered_map <int, int> mpp;
        stack <int> st;
        for (int i = n2-1; i >= 0 ; i--){
            while (!st.empty() && st.top() < nums2[i]) st.pop();
            if (st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for (int i = 0; i < n1; i++){
            nge.emplace_back(mpp[nums1[i]]);
        }
        return nge;
    }
};