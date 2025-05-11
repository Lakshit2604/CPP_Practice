# include <iostream>
# include <vector>
# include <map>
using namespace std;

// Brute 
class Solution {
    public:
      vector<int> findTwoElement(vector<int>& arr) {
          // code here
          int repeat = 0;
          int missing = 0;
          int n = arr.size();
          for(int i = 1; i<= n; i++){
              int cnt = 0;
              for (int j = 0; j< n ; j++){
                  if (arr[j] == i) cnt++;
              }
              if (cnt == 2) repeat = i; 
              else if (cnt == 0) missing = i;
          }
          return {repeat, missing};
      }
  };

// Better
class Solution {
    public:
      vector<int> findTwoElement(vector<int>& arr) {
          // code here
          int repeat = 0;
          int missing = 0;
          int n = arr.size();
          vector<int> hash(n+1,0);
          for (int i = 0; i< n; i++){
              hash[arr[i]] += 1;
          }
          for (int i = 1; i<= n ; i++){
              if (hash[i] == 2) repeat = i;
              else if (hash[i] == 0) missing = i;
          }
          return {repeat, missing};
      }
  };

  // Optimal - Sum method
  class Solution {
    public:
      vector<int> findTwoElement(vector<int>& arr) {
          // code here
          int n = arr.size();
          int arrsumN = 0;
          int arrsumN2 = 0;
          int sumN = 0;
          int sumN2 = 0;
          for (int i = 0; i < n; i++){
              sumN += i+1;
              arrsumN += arr[i];
              sumN2 += (i+1)*(i+1);
              arrsumN2 += arr[i] * arr[i];
          }
          int x = sumN - arrsumN;
          int y = sumN2 - arrsumN2;
          int z = y/x;
          int rem = 0, mis = 0, cnt = 0;
          for (int i = 0; i< n; i++){
              if ((x+z)/2 == arr[i]) cnt++; 
          }
          if (cnt == 0) return {(z-x)/2, (z+x)/2};
          return {(z+x)/2, (z-x)/2};
      }
  };

// Optimal - XOR method
class Solution {
    public:
      vector<int> findTwoElement(vector<int>& arr) {
          // code here
          int n = arr.size();
          int xr = 0;
          for (int i = 0; i < n; i++){
              xr = xr ^ arr[i];
              xr = xr ^ i;
          }
          int bitshift = 0;
          while((xr & (1<< bitshift)) != 1) bitshift++;
          int zero = 0, one = 0;
          for (int i = 0; i< n; i++){
              if (arr[i] & (1<<bitshift) == 0) zero = zero ^ arr[i];
              else one = one ^ arr[i];
              if ((i+1) & (1<< bitshift) == 1) zero = zero ^ (i+1);
              else one = one ^ (i+1);
          }
          int cnt = 0;
          for (int i = 0 ; i < n; i++){
              if (zero == arr[i]) cnt++;
          }
          if (cnt == 2) return {zero, one};
          return {one, zero};
      }
  };