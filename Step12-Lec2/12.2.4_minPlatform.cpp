# include <iostream>
using namespace std;

// Brute
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        int maxi = 0;
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if ((arr[i] >= arr[j] && arr[i] <= dep[j])) {
                    cnt++;
                }
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

// Optimal
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int n = arr.size();
        int cnt = 0;
        int maxi = 0;
        int l = 0, r = 0;
        while ( l < n){
            if (arr[l] <= dep[r]) l++, cnt++;
            else r++, maxi = max(maxi, cnt), cnt--;
        }
        return max(maxi, cnt);
    }
};
