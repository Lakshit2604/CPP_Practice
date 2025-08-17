# include <iostream>
# include <vector>
using namespace std;

// Better 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n ; i++){
            int low = 0;
            int high = m-1;
            while (low <= high){
                int mid = low + (high - low)/2;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] > target) high = mid - 1;
                else low = mid + 1;
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
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0){
            if (matrix[row][col] == target ) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};