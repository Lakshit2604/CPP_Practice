# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector <int> primes(n, 1);
        for (int i = 2; i*i <= n; i++){
            if (primes[i] == 1){
                for (int j = i*i; j < n; j += i){
                    if (primes[j] == 1) primes[j] = 0;
                }
            }
        }
        for (int i = 2; i < n; i++){
            if (primes[i] == 1) cnt++;
        }
        return cnt;
    }
};
