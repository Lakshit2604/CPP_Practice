# include <iostream>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int missingNo = 0 ;
            int n = nums.size();
            vector <int> hash(n+1,0);
            for (int i= 0; i<n; i++){
                hash[nums[i]] += 1 ;
            }
            for (int i= 0; i < hash.size(); i++){
                if (hash[i]==0){
                    missingNo = i ;
                    break;
                }
            }
        return missingNo;
        }
    };