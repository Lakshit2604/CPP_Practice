# include <iostream>
# include <vector>
using namespace std;

// 1
class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            vector <int> pos;
            vector <int> neg;
            int n = nums.size();
            vector <int> ans(n) ;
            for (int i = 0; i < n ; i++){
                if (nums[i]>0) pos.emplace_back(nums[i]);
                else neg.emplace_back(nums[i]);
            }
            for (int i =0; i < (n/2); i++){
                ans[2*i] = pos[i];
                ans[2*i+1] = neg[i];
            }
            return ans;
        }
};

// 2
class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            int n = nums.size();
            vector <int> ans(n);
            int pos =0 , neg = 1;
            for (int i = 0; i < n ; i++){
                if (nums[i]> 0) {
                    ans[pos] = nums[i];
                    pos += 2;
                }
                else {
                    ans[neg] = nums[i];
                    neg += 2; 
                }
            }
            return ans;
        }
};