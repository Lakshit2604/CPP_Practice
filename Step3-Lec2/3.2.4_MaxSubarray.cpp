# include <iostream>
# include <vector>
using namespace std;

// 1
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int maxsum = INT_MIN;
            for (int i = 0; i < n; i++ ){
                int sum = 0;
                for (int j = i; j < n ; j++){
                    sum += nums[j];
                    maxsum = max(maxsum, sum);
                }
            }
            return maxsum;
        }
};

// 2
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int maxsum = INT_MIN , sum = 0, start = 0 , n = nums.size();
            for (int i =0 ; i < n ; i++){
                if (sum == 0) start  = i;
                sum += nums[i];
                maxsum = max(maxsum, sum);
                if (sum < 0) sum = 0;
            }
            return maxsum;
        }
};