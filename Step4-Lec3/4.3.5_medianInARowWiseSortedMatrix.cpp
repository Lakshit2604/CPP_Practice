# include <iostream>
# include <vector>
using namespace std;

// Brute 
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <int> temp;
        for (int i = 0 ; i < n; i++){
            for (int j = 0; j < m; j++){
                temp.push_back(mat[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        return temp[(n*m)/2];
    }
};

// Optimal
class Solution {
  public:
    int minCol(vector <vector <int>> & mat, int n){
        int mini = INT_MAX;
        for (int i= 0; i < mat.size(); i++){
            mini = min(mini, mat[i][0]);
        }
        return mini;
    }
    
    int maxCol(vector <vector <int>> & mat, int n , int m ){
        int maxi = INT_MIN;
        for (int i = 0; i< n; i++){
            maxi = max(maxi, mat[i][m-1]);
        }
        return maxi;
    }
    
    int eleOccur(vector<vector<int>> &mat, int ele, int n, int m){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            int low = 0;
            int high = m-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if (mat[i][mid] <= ele) low = mid+1;
                else high = mid -1;
            }
            cnt += low;
        }
        return cnt;
    }
    
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int median = (n*m)/2;
        int low = minCol(mat,n);
        int high = maxCol(mat,n,m);
        while(low <= high){
            int mid = low + (high-low)/2;
            int eleOcc = eleOccur(mat, mid, n,m);
            if (eleOcc > median) high = mid -1;
            else low = mid + 1;
        }
        return low;
    }
};
