# include <iostream>
# include <vector>
using namespace std;

class Solution {
  private:
    bool canColor(int i,int j,vector<vector<int>>& edges, vector<int> &color){
        for ( auto e : edges){
            int u = e[0];
            int v = e[1];
            if ( i == u && color[v] == j) return false;
            if ( i == v && color[u] == j) return false;
        }    
        return true;
    }
    
    bool solve (int i, int v, vector<vector<int>> &edges, int m ,
    vector<int> &color){
        if ( i == v) return true;
        for ( int j = 1; j<= m; j++){
            if (canColor(i,j, edges, color)){
                color[i] = j;
                if (solve ( i +1, v, edges, m ,color)) return true;
                color[i] = 0;
            }
        }
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector <int> color(v, 0);
        return solve(0, v, edges, m, color);
    }
};