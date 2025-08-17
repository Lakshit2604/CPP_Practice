# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

// Method - 1
class Solution {
public:
    string frequencySort(string s) {
        int n = size(s);
        vector<int> hashArr(128,0);
        for (char c : s){
            hashArr[c] += 1;
        }

        auto cmp = [&](char a, char b){
            if (hashArr[a] == hashArr[b]) return a < b;
            return hashArr[a] > hashArr[b];
        };

        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

// Method - 2
class Solution {
public:
    string frequencySort(string s) {
        int n = size(s);
        vector<pair<int, char>> arr;
        unordered_map <char,int> mpp;
        string ans = "";
        for (char c : s){
            mpp[c]++;
        }

        for (auto it : mpp){
            arr.push_back({it.second, it.first});
        }

        auto cmp = [&](pair<int, char> a, pair<int, char> b){
            return a.first > b.first;
        };
        
        sort(arr.begin(), arr.end(), cmp);
        for (auto it : arr){
            ans.append(it.first, it.second);
        }
        return ans;
    }
};

// Method - 3 : Bucket Sort
class Solution {
public:
    string frequencySort(string s) {
        int n = size(s);
        string ans = "";
        unordered_map <char, int> mpp;
        vector<vector<char>> arr(n+1);
        for (char c : s){
            mpp[c]++;
        }
        for (auto it : mpp){
            arr[it.second].push_back(it.first);
        }
        for (int i = n; i > 0; i--){
            for (char c : arr[i]) ans.append(i,c);
        }
        return ans;
    }
};

// Method - 4 : Priority Queue
class Solution {
public:
    string frequencySort(string s) {
        int n = size(s);
        string ans = "";
        unordered_map <char, int> mpp;
        priority_queue<pair <int,char>> pq;
        for (char c : s){
            mpp[c]++;
        }
        for (auto it : mpp){
            pq.push({it.second, it.first});
        }
        while (!pq.empty()){
            ans.append(pq.top().first, pq.top().second);
            pq.pop();
        }
        return ans;
    }
};