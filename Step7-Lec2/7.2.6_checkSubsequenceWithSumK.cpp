# include <iostream>
# include <vector>
using namespace std;

// Takes much time to execute
class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        for ( int i = 1; i < (1<<n); i++){
            int sum = 0;
            for (int j = 0; j < n ; j++){
                if ( (i & (1 << j)) != 0) sum += arr[j];
            }
            if (sum == k) return true;
        }
        return false;
    }
};

// Optimal
class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return helper(0, n, arr, k, 0);
    }
    
    bool helper(int i, int n, vector <int> &arr, int k, int sum){
        if (sum == k) return true;
        if ( sum > k || i == n) return false;
        sum += arr[i];
        if (helper(i+1, n, arr, k, sum)) return true;
        sum -= arr[i];
        if (helper(i+1, n, arr, k, sum)) return true ; 
        return false;
    }
};