# include <iostream>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>&i2){return (i1[1] < i2[1]);});
        int n = intervals.size();
        int cnt = 0;
        int check = 0;
        for (int i = 1; i < n; i++){
            if (intervals[i][0] < intervals[check][1]) cnt++;
            else check = i;
        }
        return cnt;
    }
};