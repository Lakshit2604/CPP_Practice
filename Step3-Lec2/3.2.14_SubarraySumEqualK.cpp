# include <vector>
# include <iostream>
using namespace std;
// Brute
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int cnt = 0;
            int n = nums.size(); 
            for(int i = 0 ; i < n ; i++){
                for (int j = i ; j < n; j++){
                    int sum = 0;
                    for (int l = i; l<=j;l++){
                        sum += nums[l];
                    }
                    if (sum == k) cnt += 1 ;
                }
            }
            return cnt;
        }
    };

// Better
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int cnt = 0;
            int n = nums.size(); 
            for(int i = 0 ; i < n ; i++){
                int sum = 0;
                for (int j = i ; j < n; j++){
                    sum += nums[j];
                    if (sum == k) cnt += 1 ;
                }
            }
            return cnt;
        }
    };

//Optimal
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            int cnt = 0; 
            int preSum = 0;
            unordered_map <int, int> mpp;
            mpp[0] = 1;
            for (int i =0; i < n ; i++){
                preSum += nums[i];
                int rem = preSum - k;
                cnt += mpp[rem];    
                mpp[preSum] += 1;
            }
            return cnt;
        }
    };