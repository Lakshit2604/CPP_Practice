# include <iostream>
# include <vector>
# include <unordered_set>
# include <map>
using namespace std;

// Brute
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            vector <int> ans;
            unordered_set <int> st; 
            for (int i = 0; i < n; i++){
                int count = 0;
                for (int j = 0; j < n; j++){
                    if (nums[i] == nums[j]) count++;
                }
                if (count > (n/3)){
                    st.insert(nums[i]);
                } 
                if (st.size() == 2) break;
            }
            for( int i : st){
                ans.emplace_back(i);
            }
            return ans;
        }
};

//Better
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            map<int, int> mpp;
            vector <int> ans;
            for (int i = 0; i< n; i++){
                mpp[nums[i]] += 1;
            }
            for (auto it : mpp){
                if (it.second > (n/3)) ans.emplace_back(it.first);
            }
            return ans;
        }
    };

// Optimal
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            vector <int> ans ;
            int el1;
            int el2;
            int cnt1 =0; 
            int cnt2 = 0;
            for (int i = 0; i < n ; i++){
                if (cnt1 == 0 && el2 != nums[i]){
                    el1 = nums[i];
                    cnt1 = 1;
                }
                else if (cnt2 == 0 && el1 != nums[i]){
                    el2 = nums[i];
                    cnt2 = 1;
                }
                else if (nums[i] == el1) cnt1++;
                else if (nums[i] == el2) cnt2++;
                else {
                    cnt1--;
                    cnt2--;
                } 
            }
            if (cnt1){
                int cnt = 0;
                for(int i = 0; i< n; i++){
                    if (nums[i] == el1) cnt++;
                }
                if (cnt > (n/3)) ans.emplace_back(el1);
            }
    
            if (cnt2){
                int cnt = 0;
                for(int i = 0; i< n; i++){
                    if (nums[i] == el2) cnt++;
                }
                if (cnt > (n/3)) ans.emplace_back(el2);
            }
            return ans;
        }
    };