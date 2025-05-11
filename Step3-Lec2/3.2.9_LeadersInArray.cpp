# include <iostream>
# include <vector>
using namespace std;

// Brute force
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector <int> leader ;
        for(int i =0; i<n; i++){
            int count = 1;
            for (int j = i; j< n; j++){
                if (arr[i] < arr[j]){
                    count = 0;
                    break;
                }
            }
            if(count) leader.push_back(arr[i]);
        }
        return leader;
    }
};

//Optimal
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        int maxi = 0;
        for (int i = n-1; i>=0 ; i--){
            if (arr[i] >= maxi){
                maxi = arr[i];
                result.push_back(maxi);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

