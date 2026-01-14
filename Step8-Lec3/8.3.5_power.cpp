# include <iostream>
using namespace std;

class Solution {
private:
    double solve(double x, long n){
        n = abs(n);
        if (n == 1) return x;
        if ( (n & 1) == 0){
            return solve( x * x, n/2);
        }
        return x * solve(x, n-1);
    }

public:
    double myPow(double x, int n) {
        if ( n == 0) return 1;
        if ( x == 0 || x == 1) return x;
        double ans = solve(x, n); 
        if ( n > 0) return ans;
        return (1/ans);   
    }
};