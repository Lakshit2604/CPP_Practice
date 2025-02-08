# include <iostream>
using namespace std;
class Solution {
  public:
    void printNos(int N) {
        // code here
        if (N<1) return;
        cout << N << " ";
        printNos(N+1);
    }
};
int main(){
    Solution sol;
    sol.printNos(4);
    return 0;
}