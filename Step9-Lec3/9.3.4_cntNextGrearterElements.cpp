# include <iostream>
using namespace std;


class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n = arr.size();
        vector <int> ans;
        for (int i : indices){
            int cnt =0;
            for (int j = i+1; j < n; j++){
                if ( arr[j] > arr[i]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};