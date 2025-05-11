# include <iostream>
# include <vector>

using namespace std;

// Better
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size(); 
            int n = matrix[0].size();
            vector<int> col(n,0);
            vector <int> row(m,0);
            for (int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if (matrix[i][j]==0){
                        col[j] = 1;
                        row[i] = 1;
                    }
                }
            }
            for(int i = 0; i < m; i++){
                for (int j = 0; j < n ; j++ ){
                        if (row[i] || col[j]) matrix[i][j] = 0;
                    }
                }
            }
    };

// Optimal
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int col0 = 1;
            int m = matrix.size();
            int n = matrix[0].size();
            for(int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    if (matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        if (j == 0){
                            col0 = 0;
                        }
                        else {
                        matrix[0][j] = 0;
                        }
                    }
                }
            }
    
            for (int i = m-1; i>0; i--){
                for(int j = n-1; j > 0; j--){
                    if (matrix[i][j] != 0){
                        if(matrix[0][j] == 0 || matrix[i][0] == 0){
                            matrix[i][j] = 0;
                        }
                    }
                }
            }
    
            if (matrix[0][0] == 0){
                for (int i = 0; i< n; i++) matrix[0][i] = 0;
            }
            
            if (col0 == 0){
                for (int i = 0; i< m; i++) matrix[i][0] = 0;
            }
        }
    };