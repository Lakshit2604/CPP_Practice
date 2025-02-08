# include <iostream>
using namespace std;

class Solution {
  public:
    // Complete this function
    void printNos(int n) {
        // Your code here
        int num = 1;
        if(n>0 && num <= n){
            cout << num << " ";
            num ++;
            printNos(n);
        }
    }
};