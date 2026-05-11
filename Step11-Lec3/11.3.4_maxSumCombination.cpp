# include <iostream>
# include <queue>
# include <vector>
# include <map>
using namespace std;

// Brute
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        priority_queue <int, vector<int>> pq;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                pq.push(a[i] + b[j]);
            }
        }
        vector <int> ans;
        while (!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
            if (ans.size() == k) break;
        }
        return ans;
    }
};

// Optimal
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        int n = a.size();
        int m = b.size();
        
        priority_queue<pair<int, pair<int,int>>> pq;
        map <pair<int,int>, int> mpp;
        
        vector<int> ans;
        
        pq.push({a[0] + b[0], {0,0}});
        mpp[{0,0}] = 1;
        
        while(!pq.empty() && ans.size() < k) {
            auto top = pq.top();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            pq.pop();
            
            if(i + 1 < n && mpp.find({i+1, j}) == mpp.end()) {
                pq.push({a[i+1] + b[j], {i+1, j}});
                mpp[{i+1, j}] = 1;
            }
            
            if(j + 1 < m && mpp.find({i, j+1}) == mpp.end()) {
                pq.push({a[i] + b[j+1], {i, j+1}});
                mpp[{i, j+1}] = 1;
            }
        }
        return ans;
    }
};