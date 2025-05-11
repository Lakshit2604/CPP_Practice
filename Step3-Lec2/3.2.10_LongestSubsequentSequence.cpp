# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;

// Brute
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int maxl = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++){
                int length = 1;
                int x = nums[i];
                while(ls(nums,x+1)){
                    length += 1;
                    x += 1;
                }
                maxl = max(maxl, length);
            }
            return maxl;
        }
        bool ls(vector<int>& nums, int num){
            for (int i = 0; i<nums.size(); i++){
                if(nums[i] == num){
                    return true;
                }
            }
            return false;
        }
    };

// Better
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int maxl = 0;
            int length = 0;
            int prev = INT_MIN;
            for(int i = 0; i < n; i++){
                if (nums[i]-1 == prev){
                    length += 1;
                }
                else if (nums[i]!= prev){
                    length = 1;
                }
                prev = nums[i];
                maxl = max(maxl,length);
            }
            return maxl;
        }
    };

// Optimal
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            int maxl = 0;
            unordered_set<int> st;
            for (int i = 0; i < n ; i++){
                st.insert(nums[i]);
            }
    
            for(auto i : st){
                if(st.find(i-1) == st.end()){
                    int cnt = 1;
                    int x = i;
                    while(st.find(x+1) != st.end()){
                        cnt += 1;
                        x += 1;
                    }
                    maxl = max(maxl, cnt);
                }
            }
            return maxl;
        }
    };