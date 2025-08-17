# include <iostream>
# include <vector>
using namespace std;

// Linear Search
// My approach
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing = arr[0] - 1;
        int n = arr.size();
        if (k < arr[0]) return k;
        for (int i = 1 ; i < n; i++){
            if (missing + (arr[i] - arr[i-1] - 1) >= k){
                return arr[i-1] + k - missing;
            }
            missing += (arr[i] - arr[i-1] - 1);
        } 
        return arr[n-1] + k - missing;
    }
};

// Striver approach
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++){
            if  ( k >= arr[i]) k++;
            else return k;
        }
        return k;
    }
};

// Binary Search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0; 
        int high = n - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if ((arr[mid] - mid - 1) >= k) high = mid - 1;
            else low = mid + 1;
        }
        return k + low;
    }
};