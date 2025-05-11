# include <iostream>
# include <vector>
# include <map>
using namespace std;

// Brute
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int maxPro = INT_MIN;
            for (int i = 0; i< n; i++){
                for (int j = i; j < n; j++){
                    int pro = 1;
                    for (int k = i; k <= j; k++){
                        pro *= nums[k];
                        maxPro = max(maxPro, pro);
                    }
                }
            }
            return maxPro;
        }
    };

// Better 
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int maxPro = INT_MIN;
            for (int i = 0; i< n; i++){
                int pro = 1;
                for (int j = i; j < n; j++){
                    pro *= nums[j];
                    maxPro = max(maxPro, pro);                
                }
            }
            return maxPro;
        }
    };

// Optimal
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxPro = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for (int i = 0; i < n; i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxPro = max(maxPro,max(prefix,suffix));
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
        }
        return maxPro;
    }
};