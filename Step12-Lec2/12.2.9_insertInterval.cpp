# include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        while( (i < n )&& (intervals[i][1] < newInterval[0])){
            ans.push_back(intervals[i]);
            i++;
        }
        while( (i < n) && (intervals[i][0] <= newInterval[1])){
            int newS = min(intervals[i][0], newInterval[0]);
            int newE = max(intervals[i][1], newInterval[1]);
            newInterval = {newS, newE};
            i++;
        }
        ans.push_back(newInterval);
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};