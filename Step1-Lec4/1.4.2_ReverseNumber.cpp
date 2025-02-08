# include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        long copy = abs(long(x));
        while(copy > 0){
            int lastDigit = copy % 10;
            copy /= 10;
            if(rev > (INT_MAX - lastDigit)/10){
                rev = 0;
                break;
            } else {
                rev = rev*10 + lastDigit;
            }
        }
        if(x<0) return -rev;  else return rev; 
    }
};