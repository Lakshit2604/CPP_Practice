# include <iostream>
using namespace std;

// Better
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector <int> left;
        int prev = 1, curr = 1;
        int n = ratings.size();
        for (int i = 0; i < n; i++){
            if ((i > 0) && (ratings[i] > ratings[i-1])) left.push_back(left[i-1]+1);
            else left.push_back(1);
        }
        int sum = max(left[n-1], 1);
        for (int i = n-2; i >= 0; i--){
            if (ratings[i] > ratings[i+1]){
                curr = prev + 1;
                prev = curr;
            }   
            else {
                curr = prev = 1;
            }
            sum += max(left[i], curr);
        }
        return sum;
    }
};

// Optimal
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        while(i < n){
            int peak = 1;
            while ( (i < n) && (ratings[i] > ratings[i-1])){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while ( (i < n) && (ratings[i] < ratings[i-1])){
                sum += down;
                down++;
                i++;
            }
            if (down > peak) sum += (down - peak);
            while ( (i < n) && (ratings[i] == ratings[i-1])){
                sum += 1;
                i++;
            }
        }
        return sum;
    }
};