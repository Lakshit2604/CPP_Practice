# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long xorAll = 0;
        for ( int i = 0; i < n ; i++){
            xorAll = xorAll ^ nums[i];
        }
        int dBit = (xorAll ^ xorAll - 1) & xorAll;
        int b1 = 0, b2 = 0;
        for (int i = 0; i < n; i++){
            if ((nums[i] & dBit) != 0) b1 = b1 ^ nums[i];
            else b2 = b2 ^ nums[i];
        }
        return {b1, b2};
    }
};