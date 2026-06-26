# include <iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    struct Data{
        int start; 
        int end;
        int index;
        
        Data(int s, int e, int i){
            start = s;
            end = e;
            index = i;
        }
    };
    
    // bool comp(Data &d1, Data &d2){
    //     if (d1.end <= d2.end) return true;
    //     return false;
    // }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<Data> arr;
        
        for (int i = 0; i < n; i++){
            Data d(start[i], end[i], i);
            arr.push_back(d);
        }    
        
        sort(arr.begin(), arr.end(), [](Data &d1, Data &d2){ return d1.end < d2.end ;});
        
        int cnt = 0, lastEnd = -1;
        for (int i = 0; i < arr.size(); i++){
            if(arr[i].start > lastEnd) {
                cnt++;
                lastEnd = arr[i].end;
            }
        }
        return cnt;
    }
};