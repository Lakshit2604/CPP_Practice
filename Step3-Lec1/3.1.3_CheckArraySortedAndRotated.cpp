# include <iostream>
# include <vector>
using namespace std;


class Solution {
    public:
        bool check(vector<int>& nums) {
            int rotate =0 ;
            for(int i =0; i < nums.size()-1;i++){
                if (nums[i]> nums[i+1]){
                    rotate = i+1 ;
                    break;
                } 
            }
            if (rotate == 0) return true;
            else {
                vector<int> temp;
                for(int i =0 ; i < rotate; i++){
                    temp.emplace_back(nums[i]);
                }
    
                for(int i = rotate; i < nums.size(); i++){
                    nums[i-rotate] = nums[i];
                }
    
                for(int i = nums.size()-rotate  ; i < nums.size(); i++){
                    nums[i] = temp[i - (nums.size()-rotate)];
                }
    
                for (int i =0 ; i < nums.size()-1; i++){
                    if (nums[i] > nums[i+1]){
                        return false;
                    }
                }
            }
            return true;
        }
    };

    int main(){
        Solution sol;
        vector<int> nums = {2,3,4,5,1};
        cout << sol.check(nums);
        
    }