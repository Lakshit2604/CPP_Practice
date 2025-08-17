# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

// Method - 1
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty = 0;
        for (int i = 0 ; i< n; i++){
            vector <int> hash(26,0);
            for (int j = i ; j< n; j++){
                int maxi = INT_MIN, mini = INT_MAX;
                hash[s[j]-'a']++;
                for (int k = 0; k < hash.size(); k++){
                    if (hash[k] != 0){
                        // if(maxi == 0 && mini == 0) maxi = mini = hash[k];
                        maxi = max(maxi, hash[k]);
                        mini = min(mini, hash[k]);
                    }
                }
                beauty += (maxi- mini);
            }
        }
        return beauty;
    }
};

// Method - 2
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty = 0;
        for (int i = 0 ; i< n; i++){
            unordered_map <char, int> mpp;
            for (int j = i ; j< n; j++){
                int maxi = INT_MIN, mini = INT_MAX;
                mpp[s[j]]++;
                for (auto it : mpp){
                    // if(maxi == 0 && mini == 0) maxi = mini = it.second;
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                beauty += (maxi- mini);
            }
        }
        return beauty;
    }
};