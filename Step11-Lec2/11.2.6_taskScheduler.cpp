# include <iostream>
using namespace std;

// Approach - 1  
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();
        vector <int> hash(26,0);
        priority_queue <int, vector<int>> pq;
        queue <pair<int, int>> q;
        for (int i = 0; i < k; i++){
            hash[tasks[i] - 'A']++;
        }
        for (int i : hash){
            if ( i != 0) pq.push(i);
        }
        int time = 0;
        while ( !pq.empty() || !q.empty()){
            time++;
            if ( !pq.empty()){
                int freq = pq.top();
                pq.pop();
                if ( freq != 1) q.push({freq-1, time+n});
            }
            if ( q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

// Mathematical Approach
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();
        vector <int> hash(26,0);
        for (int i = 0; i < k; i++){
            hash[tasks[i] - 'A']++;
        }
        int maxFreq = *max_element(hash.begin(), hash.end());
        int cntMax = 0;
        for (int i : hash){
            if ( i == maxFreq ) cntMax++;
        }
        int res = (maxFreq-1) * (n+1) + cntMax;
        return max(res, k);
    }
};