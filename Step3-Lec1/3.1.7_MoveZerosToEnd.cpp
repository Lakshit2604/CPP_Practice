# include <iostream>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
            int j;
            for(int i = 0; i < n ; i++){
                if (nums[i]==0) {
                    j=i; 
                    break;
                }
            }
    
            for (int i = j+1; i< n; i++){
                if(nums[i]!= 0){
                    swap(nums[j],nums[i]);
                    j++;
                }
            }
        }
};