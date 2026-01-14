# include <iostream>
using namespace std;

class Solution {
  private:
    int detXor(int n){
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n+1;
        if (n % 4 == 3) return 0;
        return 0;
    }
    
  public:
    int findXOR(int l, int r) {
        // complete the function here
        return (detXor(l-1) ^ detXor(r));
    }
};