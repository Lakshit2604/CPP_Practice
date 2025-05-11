#include <iostream>
using namespace std;

class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            int left = 0;
            int maxfreq =1;
            sort(nums.begin(), nums.end());
            int totalOper = 0;
            for (int right = 0; right < nums.size(); right++){
                totalOper += nums[right]-nums[left];
    
                while(totalOper > k){
                    totalOper -= nums[right]-nums[left];
                    left+=1;
                }
                maxfreq = max(maxfreq, right - left + 1);
            }
            return maxfreq;
        }
    };

    int main(){
        Solution sol;
        vector<int> nums = {1,6,2,7}; //{1,2,6,7}
        sol.maxFrequency(nums, 3);
        return 0;
    }