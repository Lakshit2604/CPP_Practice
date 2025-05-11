# include <iostream>
# include <vector>
using namespace std;

// Optimal
class Solution {
    public:
        vector <int> num(int n){
            vector <int> num = {1};
            int ans = 1;
            for (int i = 1; i < n; i++){
                ans = (ans * (n-i))/(i);
                num.emplace_back(ans);
            }
            return num;
        }
        vector<vector<int>> generate(int numRows) {
            vector <vector <int>> pTri; 
            for (int i = 1; i <= numRows; i++){
                pTri.push_back(num(i));
            }
            return pTri;
        }
    };