# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    int hours(vector <int> & piles, int h, int k){
        int hours = 0;
        for (int i = 0; i < piles.size(); i++){
            if (hours > h) break;
            hours += (piles[i] + k - 1) /k;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        for (int i = 1; i < *max_element(piles.begin(), piles.end()); i++){
            if (hours(piles, h, i) <= h) return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector <int> piles  = {3,6,7,11};
    cout << sol.minEatingSpeed(piles, 8);
    return 0;
}