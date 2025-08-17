# include <iostream>
# include <vector>
using namespace std;

// Better
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0 ; i < n; i++){
            if (target <= matrix[i][m-1]){
                int low = 0;
                int high = m - 1;
                while (low <= high){
                    int mid = low + (high - low)/2;
                    if (matrix[i][mid] == target) return true;
                    else if (matrix[i][mid] < target) low = mid + 1;
                    else high = mid - 1;
                }
            }
        }
        return false;
    }
};

// Optimal
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n*m - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }      
        return false; 
    }
};