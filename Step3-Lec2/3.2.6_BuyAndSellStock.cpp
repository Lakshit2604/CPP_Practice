# include <iostream>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int maxprofit = 0;
            int buy = prices[0];
            for (int i = 1; i < n ; i++){
                int profit = prices[i] - buy;
                if (profit < 0){
                    buy = prices[i];
                }
                else {
                    maxprofit = max(maxprofit, profit);
                }
            }
            return maxprofit;
        }
 };