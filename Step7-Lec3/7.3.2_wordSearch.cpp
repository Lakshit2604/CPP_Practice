# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool check(int i, int j, int k, vector <vector<char>> &board, string &word){
        if ( k == word.size()) return true;
        if ( i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if ( board[i][j] == '*' || board[i][j] != word[k] ) return false;
        board[i][j] = '*';
        if (check(i-1, j, k+1, board, word)) {
            board[i][j] = word[k]; 
            return true;
            }
        if (check(i, j+1, k+1, board, word)) {
            board[i][j] = word[k]; 
            return true;
            }
        if (check(i+1, j, k+1, board, word)) {
            board[i][j] = word[k]; 
            return true;
            }
        if (check(i, j-1, k+1, board, word)) {
            board[i][j] = word[k]; 
            return true;
            }
        board[i][j] = word[k];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (check(i,j,0, board, word)) return true;
            }
        }
        return false;
    }
};