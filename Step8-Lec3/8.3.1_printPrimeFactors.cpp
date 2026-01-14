# include <iostream>
# include <vector>
using namespace std;

// Brute 
class Solution {
private:
    bool chkPrime(int n){
        int cnt = 0;
        for (int i = 2; i < n; i++ ){
            if (n % i == 0) return false;
        }
        return true;
    }
    
public:
    vector<int> primeFac(int n) {
        // code here
        vector <int> primes;
        for (int i = 2; i <= n; i++){
            if (n % i == 0){
                if (chkPrime(i)) primes.push_back(i);
            }
        }
        return primes;
    }
};

// Better 
class Solution {
private:
    bool chkPrime(int n){
        int cnt = 0;
        for (int i = 2; i*i <= n; i++ ){
            if (n % i == 0) return false;
        }
        return true;
    }
    
public:
    vector<int> primeFac(int n) {
        // code here
        vector <int> primes;
        for (int i = 1; i*i <= n; i++){
            if (n % i == 0){
                if ((i != 1) && chkPrime(i)) primes.push_back(i);
                if ((i != (n/i)) && chkPrime(n/i)) primes.push_back(n/i);
            }
        }
        return primes;
    }
};

// Optimal 
class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector <int> primes;
        for (int i = 2; i*i <= n; i++){
            if (n % i == 0){
                primes.push_back(i);
                while (n % i == 0){
                    n = n / i;
                }
            }
        }
        if (n != 1) primes.push_back(n);
        return primes;
    }
};