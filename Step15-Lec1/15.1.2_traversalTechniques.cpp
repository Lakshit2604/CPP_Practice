#include <iostream>
# include <sstream>
# include <string>
using namespace std;

class Solution {
  public:
    void solve(int V,vector<vector<int>> &adj, vector<int> &dfs, vector<int> &vis){
        for (int i : adj[V]){
            if ( vis[i] == 0){
                vis[i] = 1;
                dfs.push_back(i);
                solve(i, adj, dfs, vis);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj(V);
        for (auto i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dfs, vis(V,0);
        vis[0] = 1;
        dfs.push_back(0);
        solve(0, adj, dfs, vis);
        return dfs;
    }
    
    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj(V);
        for (auto i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> vis(V,0);
        vector<int> bfs;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            bfs.push_back(top);
            for (int i : adj[top]){
                if (vis[i] == 0){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return bfs;
    }
};
