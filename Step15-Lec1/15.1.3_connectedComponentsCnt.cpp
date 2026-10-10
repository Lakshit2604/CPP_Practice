#include <iostream>
# include <sstream>
# include <string>
using namespace std;

class Solution {
private:
    void dfs(int i, vector<vector<int>> &adjLs, vector<int> &vis, vector<int> &route){
        if ( vis[i] == 1) return;
        vis[i]++;
        for (int j : adjLs[i]){
            if (!vis[j]){
                route.push_back(j);
                dfs(j, adjLs, vis, route);
            }
            else{
                vis[j]++;
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjLs(n);
        for (auto i : edges){
            int u = i[0];
            int v = i[1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }

        vector<int> vis(n,0);
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                vector<int> route;
                // route.push_back(i);
                dfs(i, adjLs, vis, route);
                
                int m = route.size();
                bool flag = true;
                for (int k : route){
                    if ( k == i ){
                        if (vis[k] != m+1) {
                            flag = false;
                            break;
                        }
                    }
                    else{
                        if ( vis[k] != m){
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) cnt++;
            }
        }
        return cnt;
    }
};