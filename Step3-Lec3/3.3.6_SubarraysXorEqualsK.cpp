# include <iostream>
# include <vector>
# include <map>
using namespace std;

// Brute
class Solution {
    public:
      long subarrayXor(vector<int> &arr, int k) {
          // code here
          long cnt = 0;
          int n = arr.size();
          for (int i = 0; i< n; i++){
              for(int j = i; j < n; j++){
                  int xr = 0;
                  for (int l = i; l<= j; l++){
                      xr = xr ^ arr[l];
                  }
                  if (xr == k) cnt++;
              }
          }
          return cnt;
      }
  };

// Better
class Solution {
    public:
      long subarrayXor(vector<int> &arr, int k) {
          // code here
          long cnt = 0;
          int n = arr.size();
          for (int i = 0; i< n; i++){
              int xr = 0;
              for(int j = i; j < n; j++){
                  xr = xr ^ arr[j];
                  if (xr == k) cnt++;
              }
          }
          return cnt;
      }
  };

// Optimal
class Solution {
    public:
        long subarrayXor(vector<int> &arr, int k) {
            // code here
            int n = arr.size();
            long cnt = 0;
            map <int, int> mp;
            mp[0] = 1;
            int xr = 0;
            for (int i = 0; i < n; i++){
                xr = xr ^ arr[i];
                int rem = xr ^ k;
                cnt += mp[rem];
                mp[xr] += 1;
            }
            return cnt;
        }
};