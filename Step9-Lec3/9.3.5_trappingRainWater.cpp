# include <iostream>
# include <vector>
using namespace std;

// Brute 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        vector <int> pge(n);
        vector <int> nge(n);
        nge[n-1] = height[n-1];
        pge[0] = height[0];
        for (int i = 1; i < n; i++){
            pge[i] = max(height[i], pge[i-1]);
        }
        for (int i = n-2; i >= 0; i--){
            nge[i] = max(height[i], nge[i+1]);
        }
        for (int i = 0; i < n; i++){
            if ( height[i] < pge[i] && height[i] < nge[i]){
                water += min(pge[i] , nge[i]) - height[i];
            }
        }
        return water;
    }
};

// Optimal 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, lmax = 0, rmax = 0;
        int water = 0;
        while(l < r){
            if ( height[l] < height[r]){
                if (height[l] <= lmax) water += lmax - height[l];
                else lmax = height[l];
                l++;
            }
            else{
                if (height[r] <= rmax ) water += rmax - height[r];
                else rmax = height[r];
                r--;
            }
        }
        return water;
    }
};