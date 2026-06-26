# include <iostream>
# include <vector>
using namespace std;

// Approach 1: Time limit exceeds
class Solution {
  public:
    static bool comp (pair<int, int> &p1, pair<int, int> &p2){
        if (p1.second > p2.second) return true;
        return false;
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n ; i++){
            arr.push_back({deadline[i], profit[i]});
        }
        sort(arr.begin(), arr.end(), comp);
        vector<int> hash(n+1,-1);
        int job = 0;
        int prof = 0;
        for (auto i : arr){
            int dl = i.first;
            while (dl > 0) {
                if (hash[dl] == -1){
                    hash[dl] = i.second;
                    job++;
                    prof += i.second;
                    break;
                }   
                dl--;
            }
        }
        return {job, prof};
    }
};

