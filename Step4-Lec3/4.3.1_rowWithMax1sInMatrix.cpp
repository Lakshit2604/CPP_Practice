# include <iostream>
# include <vector>
using namespace std;

// Brute 
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int max_one = 0;
        int ind = 0;
        for (int i = 0; i < m ; i++){
            int sum = 0;
            for (int j = 0; j < n; j++){
                sum += mat[i][j];
            }
            if (sum > max_one){
                max_one = sum;
                ind = i;
            }
        }
        return {ind, max_one};
    }
};

// Optimal (Binary Search - TC = O(nlogm))
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int first_occ = INT_MAX;
        int ind = -1;
        for (int i = 0; i < n ; i++){
            int low = 0;
            int high = m-1;
            if (arr[i][high] == 0) continue;
            if (arr[i][low] == 1) return i;
            while (low <= high){
                int mid = low + (high - low)/2;
                if (arr[i][mid] == 1) high = mid - 1;
                else low = mid + 1;
            }
            if (low < first_occ){
                first_occ = low;
                ind = i;
            }
        }
        return ind;
    }
};

// (TC - O(n+m))
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int row = 0;
        int col = m-1;
        int ans = -1;
        while (col >= 0 && row < n) {
            if (arr[row][col] == 0){
                row++;
                continue;
            }
            else{
                ans = row;
                col--;
            }
        }
        return ans;
    }
};