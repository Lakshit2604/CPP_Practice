# include <iostream>
# include <unordered_map>
using namespace std;

// Brute
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map <int, int> mpp;
        vector<int> dup = arr;
        sort(dup.begin(), dup.end());
        int rank = 1;
        for (int i = 0; i < n; i++){
            if (mpp.find(dup[i]) == mpp.end()) mpp[dup[i]] = rank, rank++;
        }
        for (int i = 0; i < n; i++){
            dup[i] = mpp[arr[i]];
        }
        return dup;
    }
};

// Better
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if ( n == 0) return {};
        vector<int> index(n);
        for (int i = 0; i < n; i++){
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&](int a, int b){return arr[a] < arr[b];});
        vector<int> ans(n);
        int rank = 1;
        for (int i = 0; i < n-1; i++){
            ans[index[i]] = rank; 
            if ((arr[index[i]] != arr[index[i+1]])) rank++;
        }
        ans[index.back()] = rank;
        return ans;
    }
};

// Optimal 
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if ( n == 0) return {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++){
            pq.push({arr[i], i});
        }
        vector<int> ans(n);
        int rank = 1;
        while (!pq.empty()){
            int ind = pq.top().second;
            ans[ind] = rank; 
            pq.pop();
            if (!pq.empty() && arr[pq.top().second] != arr[ind]) rank++;
        }
        return ans;
    }
};