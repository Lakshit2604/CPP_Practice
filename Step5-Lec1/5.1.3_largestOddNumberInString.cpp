# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = size(num);
        if (num[n-1] % 2 == 1) return num; 
        while (n >0){
            if (num[n-1] % 2 == 1) break;
            n--;
        }
        return num.substr(0,n);
    }
};