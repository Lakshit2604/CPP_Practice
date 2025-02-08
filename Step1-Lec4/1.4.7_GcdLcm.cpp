#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        vector <int> v;
        int gcd = 0;
        int lcm = 1;
        int a1 = a ;
        int b1 = b;
        while(a1 >0 && b1 >0){
            if(a1 > b1) a1 %= b1; else b1%= a1;
        }
        if (a1 == 0) gcd = b1; else gcd = a1;
        lcm = gcd * (a/gcd) * (b/gcd);
        v.emplace_back(lcm);
        v.emplace_back(gcd);
        return v;
    }
};