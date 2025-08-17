# include <iostream>
# include <vector>
using namespace std;

// Better 
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;
        int row = 0;
        int col = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m ; j++){
                if (mat[i][j] > maxi){
                    maxi = mat[i][j];
                    row = i;
                    col = j;
                }
            }
        }
        return {row, col};
    }
};

// Optimal
class Solution {
public:
    int maxiRow(vector<vector<int>> & mat, int mid){
        int maxi = 0, row = 0;
        for (int i = 0; i < mat.size(); i++){
            if (mat[i][mid] > maxi){
                maxi = mat[i][mid];
                row = i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++){
            int low = 0; 
            int high = m-1;
            while (low <= high){
                int mid = low + (high - low )/2;
                int maxRow = maxiRow(mat, mid);
                int left = mid - 1 >= 0 ? mat[maxRow][mid-1] : -1;
                int right = mid + 1 < m ? mat[maxRow][mid+1] : -1;
                if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) return {maxRow, mid};
                else if (mat[maxRow][mid] > left) low = mid + 1;
                else high = mid - 1;
            }
        }
        return {-1,-1};
    }
};

