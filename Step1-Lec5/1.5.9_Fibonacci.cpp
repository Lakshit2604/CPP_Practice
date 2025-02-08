# include <iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int a = 0;
        int b = 1;
        int c =0;
        for (int i = 2; i<=n; i++){    
            c = a+b;
            a = b; 
            b = c;
        }
    return c;
    }
};

// by Recursion :
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int first = fib(n-1);
        int second = fib(n-2);
        return first + second;
    }
};