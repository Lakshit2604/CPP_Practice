# include <iostream>
using namespace std;

class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int cnt = 0;
        while( n > 0){
            cnt += (n & 1);
            n = n >> 1;
        }
        return cnt;
    }
};

// Optimal
class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int cnt = 0;
        while ( n > 0){
            n = n & (n - 1);
            cnt += 1;
        }
        return cnt;
    }
};