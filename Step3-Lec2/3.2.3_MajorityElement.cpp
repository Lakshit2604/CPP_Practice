# include <iostream>
# include <map>
using namespace std;
// 1
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            map <int,int> mp;
            int result = 0;
            for (int i = 0; i < nums.size(); i++){
                mp[nums[i]] += 1;
            }
            for (auto it : mp){
                if (it.second > nums.size()/2) result = it.first;
            }
        return result;
        }
};

// 2
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int ele = nums[0];
            int count = 1;
            for (int i = 1; i < nums.size(); i++){
                if (count == 0) ele = nums[i];
                if (nums[i] == ele) count++;
                else count--; 
            }
            return ele;
        }
};