# include <iostream>
# include <vector>
using namespace std;

// for 4 Directions
class Solution {
  public:
    void helper(int i, int j, int n, vector<vector<int>> & maze, vector<string> &ans, string &ds){
        if ( i == (n - 1) && j == (n - 1)){
            ans.push_back(ds);
            return;
        }
        maze[i][j] = -1;
        if (i+1 < n && maze[i+1][j] == 1){
            ds.push_back('D');
            helper(i+1, j, n, maze, ans, ds);
            ds.pop_back();
        }
        if (j-1 >= 0 && maze[i][j-1] == 1){
            ds.push_back('L');
            helper(i, j-1, n, maze, ans, ds);
            ds.pop_back();
        }
        if (j+1 < n && maze[i][j+1] == 1){
            ds.push_back('R');
            helper(i, j+1, n, maze, ans, ds);
            ds.pop_back();
        }
        if (i-1 >= 0 && maze[i-1][j] == 1){
            ds.push_back('U');
            helper(i-1, j, n, maze, ans, ds);
            ds.pop_back();
        }
        maze[i][j] = 1;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze){
        int n = maze.size();
        vector <string> ans;
        string ds;
        helper(0, 0,n, maze,ans, ds);
        return ans;
    }
};

// For more than 4 directions : string of directions with vector of moves
class Solution {
  public:
    void helper(int i, int j, int n, vector<vector<int>> & maze, vector<string> &ans, 
    string &ds, vector<int> &di, vector<int> &dj){
        if ( i == (n - 1) && j == (n - 1)){
            ans.push_back(ds);
            return;
        }
        string move = "DLRU";
        maze[i][j] = -1;
        for ( int k = 0; k < 4; k++){
            int nexti = i + di[k];
            int nextj = j + dj[k];
            if ( nexti < 0 || nextj < 0 || nexti >= n || nextj >= n ) continue;
            if ( maze[nexti][nextj] == 1 ){
                ds.push_back(move[k]);
                helper(nexti, nextj, n, maze, ans, ds, di, dj);
                ds.pop_back();
            }
        }
        maze[i][j] = 1;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze){
        int n = maze.size();
        vector <string> ans;
        vector <int> di = {1,0, 0, -1};
        vector <int> dj = {0, -1, 1,0};
        string ds;
        helper(0, 0,n, maze,ans, ds, di, dj);
        return ans;
    }
};