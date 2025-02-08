# include <iostream>
using namespace std;
class Solution {
  public:
    // Complete this function
    int num = 1;

    void printNos(int n) {
        // Your code here
        if(n>0 && num <= n){
            cout << num << " ";
            num ++;
            printNos(n);
        }
    }
};
int main (){
    Solution sol;
    sol.printNos(5);
    return 0;
}