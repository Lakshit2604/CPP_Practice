# include <iostream>
# include <vector>
# include <map>
using namespace std;

//Optimal
class Solution {
    public:
        int maxLen(vector<int>& arr) {
            // code here
            int n = arr.size();
            map<int, int> mpp;
            int sum = 0;
            int maxlen = 0;
            for (int i = 0; i < n; i++){
                sum += arr[i];
                if (sum == 0) maxlen = i+1;
                else {
                    if (mpp.find(sum) != mpp.end()){
                        maxlen = max(maxlen, i- mpp[sum]);
                    }
                    else mpp[sum] = i;
                }
            }
            return maxlen;
        }
};
  