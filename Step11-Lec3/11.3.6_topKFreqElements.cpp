# include <iostream>
# include <queue>
using namespace std;

// Better
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        vector<int> ans;
        for (int i : nums) mpp[i]++;
        for (auto i : mpp){
            pq.push({i.second, i.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Optimal - Bucket Sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for (int i : nums) mpp[i]++;
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for (auto i : mpp){ 
            int freq = i.second;
            int ele = i.first;
            bucket[freq].push_back(ele);
        }

        n = bucket.size();
        for(int i = n-1; i >= 0; i--){
            for ( int j : bucket[i]){
                ans.push_back(j);
                if ( ans.size() == k) return ans; 
            }
        }
        return ans;
    }
};