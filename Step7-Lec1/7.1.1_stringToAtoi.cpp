# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s == "") return 0;
        return convert(s,0, false, false, false, 0 );
    }
    int convert(string s, int i, bool sign, bool digitOcc, bool signOcc, int result){
        if (i == s.size()) return sign ? -result : result;
        if ( s[i] == ' ' ){
            if (digitOcc || signOcc) return sign ? -result : result;
            return convert(s, i+1, sign, digitOcc, signOcc, result);
        }
        if (s[i] == '+'){
            if (digitOcc || signOcc) return sign ? -result : result;
            return convert(s, i+1, sign, digitOcc, true, result);
        }
        if (s[i] == '-'){
            if (digitOcc || signOcc) return sign ? -result : result;
            return convert(s, i+1, true , digitOcc, true, result);
        }
        if (!isdigit(s[i])) return sign ? -result : result;

        int digit = s[i] - '0';
        if (result > (INT_MAX - digit)/10) return sign ? INT_MIN : INT_MAX;
        result = result * 10 + digit;
        return convert(s, i+1, sign, true, signOcc, result);
    }
};