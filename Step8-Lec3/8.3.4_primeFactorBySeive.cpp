# include <iostream>
# include <vector>
using namespace std;

// Brute : From Prime Factorization method
class Solution {
  public:
    vector<int> findPrimeFactors(int N) {
        // Write your code here
        vector <int> primes;
        for (int i = 2; i*i <= N; i++){
            if ( N % i == 0){
                while ( N % i == 0){
                    primes.push_back(i);
                    N /= i;
                }
            }
        }
        if ( N != 1) primes.push_back(N);
        return primes;
    }
};

// Optimal : seive method
// User function Template for C++

class Solution {
  public:
    void sieve(){} 

    vector<int> findPrimeFactors(int N) {
        // Write your code here
        vector <int> primeFactors;
        vector <int> spf(N+1);
        for (int i = 0; i <= N; i++){
            spf[i] = i;
        }
        
        for ( int i = 2; i*i <= N; i++){
            if (spf[i] == i){
                for ( int j = i*i; j <= N; j+= i){
                    if (spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }
        
        while(N != 1){
            primeFactors.push_back(spf[N]);
            N = N/spf[N];
        }
        
        return primeFactors;
    }
};