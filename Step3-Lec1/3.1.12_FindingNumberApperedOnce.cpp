# include <iostream>
# include <vector>
using namespace std;
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int XOR = 0;
            for (int i : nums){
                XOR = XOR ^ i;
            }
            return XOR;
        }
    };