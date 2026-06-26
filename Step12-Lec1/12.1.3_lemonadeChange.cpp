# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mpp;
        for (int i :
             bills){
            mpp[i]++;
            if (i == 10){
                if (mpp[5]) mpp[5]--;
                else return false;
            }
            if ( i == 20){
                if (mpp[10] && mpp[5]) mpp[5]--, mpp[10]--;
                else if (mpp[5] >= 3) mpp[5] = mpp[5] - 3;
                else return false;
            }
        }
        return true;
    }
};