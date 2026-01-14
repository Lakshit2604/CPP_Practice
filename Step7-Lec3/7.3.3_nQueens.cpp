# include <iostream>
# include <vector>
# include <string>
using namespace std;

// Brute : Check through iteration
class Solution {
public:
    bool canPut(int i, int j, int n, vector<string> &board){
        int shift = 1;
        for ( int col = j-1; col >= 0; col--){
            if ( board[i][col] == 'Q') return false;
            if ( i - shift >= 0 && board[i - shift][col] == 'Q') return false;
            if ( i + shift < n && board[i + shift][col] == 'Q') return false; 
            shift++;
        }
        return true;
    }
    void helper(int j, int n, vector<vector<string>> &ans, vector<string> &board ){
        if ( j == n){
            ans.push_back(board);
            return;
        }
        for ( int i = 0; i < n; i++){
            if (canPut(i,j,n,board)){
                board[i][j] = 'Q';
                helper(j+1, n, ans, board);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for ( int i = 0; i < n; i++){
            board[i] = s;
        }
        helper(0, n, ans, board);
        return ans;
    }
};

// Optimal : Check through hashing
class Solution {
public:
    void helper(int j, int n, vector<vector<string>> &ans, vector<string> &board, 
    vector<int> &inLine, vector<int> &rDiag, vector<int> &lDiag){
        if ( j == n){
            ans.push_back(board);
            return;
        }
        for ( int i = 0; i < n; i++){
            if ((inLine[i] == 1) || (rDiag[i+j] == 1) || (lDiag[(n-1) + (j-i)] == 1 )) continue;
            inLine[i] = rDiag[i+j] = lDiag[(n-1)+(j-i)] = 1;
            board[i][j] = 'Q';
            helper(j+1, n, ans, board, inLine, rDiag, lDiag);
            board[i][j] = '.';   
            inLine[i] = rDiag[i+j] = lDiag[(n-1)+(j-i)] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for ( int i = 0; i < n; i++){
            board[i] = s;
        }
        vector<int> inLine(n,0);
        vector<int> rDiag(2*n - 1,0);
        vector<int> lDiag(2*n - 1,0);
        helper(0, n, ans, board, inLine, rDiag, lDiag );
        return ans;
    }
};