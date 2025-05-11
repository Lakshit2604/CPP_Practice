# include <iostream>
# include <map>
using namespace std;

class Solution {
    public:
      int longestSubarray(vector<int>& arr, int k) {
          // code here
          int maxLength =0;
          int sum=0;
          int n= arr.size();
          map<int, int> mp;
          for (int i =0; i < n; i++){
              sum += arr[i];
              if (sum == k){
                  maxLength = max(maxLength, i+1);
              }
              int rem = sum-k;
              if (mp.find(rem) != mp.end()){
                  maxLength = max(maxLength, i-mp[rem]);
              }
              if(mp.find(sum)==mp.end()){
                  mp[sum] = i;
              }
          }
          return maxLength;
      }
  };
  