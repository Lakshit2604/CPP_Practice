# include <iostream>
# include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i =0 ;
            for (int j = 1; j < nums.size(); j++){
                if(nums[i]!=nums[j]){
                    swap(nums[j],nums[i+1]);
                    i++;
                }
            }
            return i+1;
        }
    };