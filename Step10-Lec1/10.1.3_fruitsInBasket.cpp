# include <iostream>
# include <set>
# include <map>
using namespace std;

// Brute
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int max_fruits = 0;
        for (int i = 0; i < n; i++){
            int b1 = -1, b2 = -1, cnt = 0; 
            for(int j = i; j < n; j++){
                if ( b1 == -1 || fruits[j] == b1) {
                    b1 = fruits[j];
                    cnt++;
                }
                else if ( b2 == -1 || fruits[j] == b2) {
                    b2 = fruits[j];
                    cnt++;
                }
                else break;
            }
            max_fruits = max(max_fruits, cnt);
        }
        return max_fruits;
    }
};

// Brute
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;
        for (int i = 0; i < n; i++){
            int len = 0;
            set<int> st;
            for(int j = i; j < n; j++){
                st.insert(fruits[j]);
                if (st.size() > 2) {
                    maxFruits = max(maxFruits, len);
                    break;
                }
                len++;
            }
            maxFruits = max(maxFruits, len);
        }
        return maxFruits;
    }
};
// Better 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;
        int l = 0, r = 0;
        map <int, int> mpp;
        while (r < n) {
            if (mpp.find(fruits[r]) == mpp.end()){
                while(mpp.size() >= 2){
                    maxFruits = max(maxFruits, r-l);
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                    l++;
                }
            }
            mpp[fruits[r]]++;
            r++;
        }
        maxFruits = max(maxFruits, r-l);
        return maxFruits;
    }
};

// Optimal
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;
        int l = 0, r = 0;
        map <int, int> mpp;
        while (r < n) {
            mpp[fruits[r]]++;
            if (mpp.size() > 2){
                    maxFruits = max(maxFruits, r-l);
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                    l++; 
            }
            r++;
        }
        maxFruits = max(maxFruits, r-l);
        return maxFruits;
    }
};