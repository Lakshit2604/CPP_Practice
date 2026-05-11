# include <iostream>
# include <vector>
# include <map>
# include <queue>
using namespace std;

// Brute
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        int n = hand.size();
        if ( n % groupSize != 0) return false;
        unordered_map <int, int> mpp;
        for (int i = 0; i < n; i++){
            mpp[hand[i]]++;
        }
        for (int i = 0; i < n; i++){
            if ( mpp[hand[i]] == 0) continue;
            for (int j = 0; j < groupSize; j++){
                if (mpp.find(hand[i]+j) == mpp.end()) return false;
                if ( mpp[hand[i] + j] == 0) return false;
                mpp[hand[i] + j]--;
            }
        }
        return true;
    }
};

// Better
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if ( n % groupSize != 0) return false;
        priority_queue <int, vector<int>, greater<int>> pq;
        unordered_map <int, int> mpp;
        for (int i = 0; i < n; i++){
            pq.push(hand[i]);
            mpp[hand[i]]++;
        }
        while (!pq.empty()){
            int top = pq.top();
            if ( mpp[top] != 0){
                for (int j = 0; j < groupSize; j++){
                    if (mpp.find(top+j) == mpp.end()) return false;
                    if ( mpp[top + j] == 0) return false;
                    mpp[top + j]--;
                }
            }
            pq.pop();
        }
        return true;
    }
};

// Better 
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if ( n % groupSize != 0) return false;
        map <int, int> mpp;
        for (int i = 0; i < n; i++){
            mpp[hand[i]]++;
        }
        while (!mpp.empty()){
            int top = mpp.begin() -> first;
            for (int j = 0; j < groupSize; j++){
                if (mpp.find(top+j) == mpp.end()) return false;
                mpp[top + j]--;
                if (mpp[top + j] == 0) mpp.erase(top+j);
            }
        }
        return true;
    }
};

// Optimal 