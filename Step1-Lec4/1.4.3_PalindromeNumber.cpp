# include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long revNum;
        long copy = abs(long(x));
        while (copy!=0){
            int ld = copy%10;
            copy/=10;
            revNum = revNum*10 + ld; 
        }
        if(x<0) return false;
        return (x==revNum);
    }
};