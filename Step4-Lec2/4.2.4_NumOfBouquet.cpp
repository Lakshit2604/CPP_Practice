# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (n < (long long)m*k) return -1;
        int low = 1; 
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        int high = max;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (possible(bloomDay, n, mid, m ,k)) high = mid - 1 ;
            else low = mid + 1;
        }
        return low;
    }

    bool possible (vector <int> &bloomDay, int n, int d, int m , int k){
        int cnt = 0;
        int numB = 0;
        for (int i = 0 ; i < n ; i++){
            if (bloomDay[i] <= d) cnt++;
            else {
                numB += cnt/k ;
                cnt = 0;
            }
        }
        numB += cnt/k;
        if (numB >= m) return true;
        return false;
    }
};

int main (){
    Solution sol;
    vector <int> bloomDay = {1,10,3,10,2};
    cout << sol.minDays(bloomDay, 3, 1);
    return 0 ;
}