# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        priority_queue<pair<double,int>> pq;
        int n = val.size();
        for (int i = 0; i < n; i++){
            pq.push({double(val[i])/wt[i], i});
        }
        double value = 0;
        while (!pq.empty()){
            auto i = pq.top();
            if (capacity >= wt[i.second]){
                capacity -= wt[i.second];
                value += val[i.second];
            }
            else{
                value += (i.first *capacity);
                break;
            }
            pq.pop();
        }
        return value;
    }
};
