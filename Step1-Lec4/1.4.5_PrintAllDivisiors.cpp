# include <iostream>
using namespace std;

class Solution {
  public:
    int sumOfDivisors(int n) {
        int t_sum = 0;
        for (int i = 1; i <= n; i++){
            int i_sum = 1;
            for(int j =2; j <=i; j++){
                if (i%j ==0){
                    i_sum+=j;
                }
            }
            t_sum += i_sum;
        }
        return t_sum;
    }
};