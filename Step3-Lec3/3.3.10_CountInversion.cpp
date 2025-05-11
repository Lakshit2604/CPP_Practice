# include <iostream>
# include <vector>
# include <map>
using namespace std;

// Brute
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        int cntin = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1 ; j < n; j++){
                if (arr[i] > arr[j]) cntin++;
            }
        }
        return cntin;
    }
};

// Optimal
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        return mergesort(arr,0,n-1); 
    }
    int mergesort(vector <int> &arr, int low, int high){
        int cnt = 0;
        if (low == high) return cnt;
        int mid = (low+high)/2;
        cnt += mergesort(arr,low, mid);
        cnt += mergesort(arr,mid+1, high);
        cnt += merge(arr,low, mid, high);
        return cnt;
    }
    
    int merge(vector <int> &arr, int low, int mid, int high){
        int cnt = 0;
        int left = low;
        int right = mid+1;
        vector <int> temp ;
        while (left <= mid && right <= high){
            if (arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else {
                cnt += (mid-left) +1;
                temp.push_back(arr[right]);
                right++;    
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++){
            arr[i] = temp[i - low]; 
        }
        return cnt;
    }
};