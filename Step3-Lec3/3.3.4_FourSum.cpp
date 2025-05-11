# include <iostream>
# include <vector>
# include <unordered_set>
# include <map>
using namespace std;

//Brute
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            set<vector<int>> st;
            for (int i = 0; i < n-3 ; i++){
                for (int j = i+1; j < n-2; j++){
                    for(int k = j+1; k < n-1; k++){
                        for(int l = k+1; l < n; l++){
                            long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                            if (sum == target){
                                vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                                sort(temp.begin(), temp.end());
                                st.insert(temp);
                            }
                        }
                    }
                }
            }
            vector <vector<int>> ans(st.begin(), st.end());
            return ans;
        }
    };

// Better
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            set <vector<int>> st;
            for(int i =0; i < n-3; i++){
                for (int j = i+1; j < n-2; j++){
                    set <long long> hashset;
                    for (int k =j+1 ; k < n; k++){
                        long long sum = (long long) nums[i] + nums[j] + nums[k];
                        long long fourth = (long long)target - sum;
                        if(hashset.find(fourth)!= hashset.end()){
                            vector <int> temp = {nums[i], nums[j], nums[k], (int) fourth};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                        hashset.insert(nums[k]);
                    }
                }
            }
            vector <vector<int>> ans(st.begin(), st.end());
            return ans;
        }
    };

// Optimal
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            set < vector <int> > st;
            sort(nums.begin(), nums.end());
            for (int i = 0; i< n-3; i++){
                if( i> 0 && nums[i] == nums[i-1]) continue;
                for (int j = i+1; j< n-2; j++){
                    if (j > i+1 && nums[j]==nums[j-1]) continue;
                    int k = j+1;
                    int l = n-1;
                    while (k<l){
                        long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum > target) l--;
                        else if (sum < target ) k++;
                        else{
                            vector <int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            st.insert(temp);
                            k++;
                            l--;
                            while(k<l && nums[k]== nums[k-1]) k++;
                            while(k<l && nums[l] == nums[l+1]) l--;
                        }
                     }
                }
            }
            vector <vector<int>> ans(st.begin(), st.end());
            return ans;
        }
    };
