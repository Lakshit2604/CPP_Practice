# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0, r = n-1;
        int sum = 0, ans = 0;
        while (l < k){
            sum += cardPoints[l];
            l++;
        }
        ans = sum;
        if (n == k) return ans;
        while ( l > 0){
            sum -= cardPoints[--l];
            sum += cardPoints[r--];
            ans = max(ans, sum);
        }
        return ans;
    }
};