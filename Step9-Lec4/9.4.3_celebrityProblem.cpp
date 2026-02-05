# include <iostream>
# include <stack>
using namespace std;

// Brute
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector <int> hash(n,0);
        for (int i = 1 ; i < n; i++){
            for (int j = 0; j < i; j++){
                if (mat[i][j] == 0 && mat[j][i] == 1) hash[i]++;
                else if (mat[i][j] == 1 && mat[j][i] == 0) hash[j]++;
                
            }
        }
        for (int i = 0; i < n ; i++){
            if (hash[i] == n-1) return i;
        }
        return -1;
    }
};

// Optimal
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int top = 0;
        int bottom = n-1;
        while (top <= bottom){
            if (top == bottom ){
                for (int i = 0; i < n; i++){
                    if (i != top && mat[top][i] == 1) return -1;
                    if (i != top && mat[i][top] == 0) return -1;
                }
                return top;
            }
            if (mat[top][bottom] == 1) top++;
            else if (mat[bottom][top] == 1) bottom--;
            else top++, bottom--;
        }    
        return -1;
    }
};