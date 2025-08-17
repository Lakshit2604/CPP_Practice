# include <iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        if (arr.size() < k) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = sumArr(arr);
        while (low <= high){
            int mid = low + (high - low)/2;
            if (painter(arr, mid) <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    
    int sumArr(vector <int> arr){
        int sum = 0;
        for (int i = 0; i < arr.size(); i++){
            sum += arr[i];
        }
        return sum;
    }
    
    int painter(vector <int> arr, int mid){
        int sum = 0;
        int painter = 1;
        for (int i = 0; i < arr.size(); i++){
            if ((sum + arr[i]) <= mid) sum += arr[i];
            else sum = arr[i], painter++;
        }
        return painter;
    }
}; 