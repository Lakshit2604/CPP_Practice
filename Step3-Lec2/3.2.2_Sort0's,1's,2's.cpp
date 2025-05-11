# include <iostream>
# include <vector>
using namespace std;

// 1
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int count0 =0;
            int count1 = 0;
            int count2 = 0;
            int j = 0;
            for (int i= 0; i < n; i++){
                if (nums[i] == 0) count0 +=1;
                else if (nums[i] == 1) count1 +=1;
                else count2 +=1;
            }
            for (int i = 0; i < count0; i++) {
                nums[j] = 0;
                j++;
            }
            for (int i = 0; i < count1; i++) {
                nums[j] = 1;
                j++;
            }
            for (int i = 0; i < count2; i++) {
                nums[j] = 2; 
                j++;
            }
        }
    };

// 2
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int low = 0;
            int mid = 0;
            int high = n-1;
            while(mid <= high){
                if (nums[mid] == 0){
                    swap(nums[low],nums[mid]);
                    low++;
                    mid++;
                }
                else if(nums[mid] == 1){
                    mid ++;
                }
                else {
                    swap(nums[mid], nums[high]);
                    high--;
                }
            }
        }
    };