# include <iostream>
# include <vector>
using namespace std;

class Solution {
  private:
    void solve(int n , int i){
        if (i*i > n ) return;
        if ( n % i == 0){
            cout << i << ' ';
            solve(n, i+1);
            if (i*i != n){ 
                cout << (n/i) << ' ';
            }
        }
        else solve(n,i+1);
    }
    
  public:
    void print_divisors(int n) {
        // Code here.
        solve(n,1);
    }
};