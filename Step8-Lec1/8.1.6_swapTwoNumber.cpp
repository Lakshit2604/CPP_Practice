# include <iostream>
using namespace std;

class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        return {b , a};
    }
};