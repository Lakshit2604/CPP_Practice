# include <iostream>
# include <vector>
using namespace std;

// Linear Search
class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int limit = stalls[n-1] - stalls[0];
        for (int i = 1; i <= limit ; i++){
            if (possible(stalls, k, i)) continue;
            else return i-1;
        }
        return limit;
    }
    bool possible(vector <int> &stalls, int k, int d){
        int n = stalls.size();
        int last = stalls[0];
        int cow = 1;
        for (int i = 1; i < n; i++){
            if ((stalls[i] - last) >= d) cow++, last = stalls[i];
            if (cow == k) return true;
        }
        return false;
    }
};

// Binary Search
// User function Template for C++

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k){
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        while (low <= high){
            int mid = low + (high - low)/2 ;
            if (possible(stalls, k, mid) == true) low = mid + 1 ; 
            else high = mid - 1;
        }
        return high;
    }
    bool possible(vector <int> &stalls, int k, int d){
        int n = stalls.size();
        int last = stalls[0];
        int cow = 1;
        for (int i = 1; i < n; i++){
            if ((stalls[i] - last) >= d) cow++, last = stalls[i];
            if (cow == k) return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    int k = 2;
    vector <int> stalls = {1,5,17};
    cout << sol.aggressiveCows(stalls, k);
    return 0;
}