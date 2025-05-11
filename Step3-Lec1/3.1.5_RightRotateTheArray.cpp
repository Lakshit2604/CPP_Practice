# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {                                   
            int n = nums.size();
            k = k % n;
            vector<int> temp;
            
            for (int i = n-k; i<n; i++){
                temp.emplace_back(nums[i]);
            }

            for (int i = n-1; i >= k; i-- ){
                nums[i] = nums[i-k];
            }

            for(int i = 0; i < k; i++){
                nums[i] = temp[i];
            }

            // By using reverse() fucntion from STL    
            reverse(nums.begin(), nums.begin()+n);
            reverse(nums.begin(),nums.begin()+k);
            reverse(nums.begin()+k, nums.begin()+n);
        }               
};
