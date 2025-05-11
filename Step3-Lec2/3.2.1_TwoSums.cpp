# include <iostream>
# include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> mp;
        for (int i = 0; i < nums.size(); i++){
            int more = target - nums[i];
            if (mp.find(more) != mp.end()){
                result.emplace_back(i);
                result.emplace_back(mp[more]);
                break;
            }
            mp[nums[i]] = i;
        }
        return result;
    }
};