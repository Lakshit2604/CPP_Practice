# include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int newS = intervals[0][0], newE = intervals[0][1];
        vector<vector<int>> ans ;
        for (int i = 0; i < n-1; i++){
            if (newE >= intervals[i+1][0]){
                newE = max(newE, intervals[i+1][1]);
            }
            else{
                ans.push_back({newS,newE});
                newS = intervals[i+1][0];
                newE = intervals[i+1][1];
            }
        }
        ans.push_back({newS,newE});
        return ans;
    }
};