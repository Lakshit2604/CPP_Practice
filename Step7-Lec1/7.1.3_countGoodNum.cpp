# include <iostream>
using namespace std;

// Brute : runtime error
class Solution {
public:
    int mod = 1000000007;
    int countGoodNumbers(long long n) {
        long long ans = 1;
        if (n-1 == 0) return 5;
        if ((n-1) % 2 == 0) ans = (long long)5 * countGoodNumbers(n-1);
        else ans = (long long)4 * countGoodNumbers(n-1);
        return int(ans % mod);
    }
};

// Opitmal
class Solution {
public:
    int mod = 1000000007;
    long long pow(long long x, long long n){
        if ( n== 0) return 1;
        if ( n % 2 == 0) return pow ((x*x) % mod , n/2);
        return (x * pow( x, n-1)) % mod ; 
    }
    int countGoodNumbers(long long n) {
        if (n == 1) return 5;
        return (pow(5, (n+1)/2) * pow(4, n/2)) % mod;
    }
};