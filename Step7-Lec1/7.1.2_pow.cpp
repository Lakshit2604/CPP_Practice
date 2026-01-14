# include <iostream>
using namespace std;

// Brute : Iterative
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if ( n == 0) return 1;
        if ( n < 0) return 1/helper(x, -n);
        return helper(x, n);
    }
    double helper(double x, long n){
        double ans = 1;
        while (n--){
            ans = ans * x;
        }
        return ans;
    }
};

// Brute : recursive (Runtime error - stack overflow)
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if ( n == 0) return x;
        if ( n < 0) return 1/helper(x, -n);
        return helper(x, n);
    }
    double helper(double x, long n){
        if ( n == 1) return x;
        return x * helper(x, n-1);
    }
};

// Optimal : recursive
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if ( n == 0) return 1;
        if ( n < 0) return 1/helper(x, -(long)n);
        return helper(x, n);
    }
    double helper(double x, long n){
        if ( n == 1) return x;
        if ( n % 2 != 0) return x * helper(x, n-1);
        return helper(x*x, n/2);
    }
};