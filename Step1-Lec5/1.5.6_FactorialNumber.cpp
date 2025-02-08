# include <iostream>
using namespace std;

class Solution {
  public:
    int fact(int i){
        if (i<1) return 1;
        return i*fact(i-1);
    }
    
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector <long long> v;
        for (int i = 1; i <= n; i++){
            int fac = fact(i);
            if(fac > n) break;
            v.emplace_back(fac);
        }
        return v;
    }
};

int main(){
    Solution sol;
    vector <long long> v = sol.factorialNumbers(53);
    for (int i : v){
        cout << i << ' ';
    }
    return 0;
}