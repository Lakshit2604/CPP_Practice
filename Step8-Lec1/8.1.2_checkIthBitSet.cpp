# include <iostream>
using namespace std;

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        if (n & (1 << k)) return true;
        return false;
    }
};