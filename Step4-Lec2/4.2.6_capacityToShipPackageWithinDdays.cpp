# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int sum(vector <int> weights){
        int sum = 0;
        for (int i = 0 ; i < weights.size(); i++){
            sum += weights[i];
        }
        return sum;
    }

    int shipWithinDays( vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = sum(weights);
        while (low <= high){
            int mid = low + (high - low)/2;
            if (check(weights, mid, days) <= days) high = mid -1 ;
            else low = mid + 1;
        }
        return low;
    }

    int check(vector <int> weights, int mid, int days){
        int sum = 0;
        int day = 1;
        for (int i = 0; i < weights.size(); i++){
            if (sum + weights[i] <= mid) sum += weights[i];
            else {
                sum = weights[i];
                day++;
            }
        }
        return day;
    }
}; 