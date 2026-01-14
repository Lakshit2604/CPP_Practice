# include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long quotient = 0;
        int sign = 0;
        long n = dividend;
        long d = divisor;

        if (n < 0 ){
            n = -n;
            sign = !sign;
        }
        if ( d < 0){
            d = -d;
            sign = !sign;
        }

        while(n >= d){
            int cnt = 0;
            while ( n >= (d << (cnt +1) )){
                cnt++;
            }
            n -= (d << cnt);
            quotient += (1 << cnt);  
        }
        if ( quotient == (1 << 31)){
            if ( sign ) return INT_MIN;
            return INT_MAX;
        }
        if (sign != 0) return -quotient;
        return quotient; 
    }
};