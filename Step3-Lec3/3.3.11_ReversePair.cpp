# include <iostream>
# include <vector>
# include <map>
using namespace std;

// Better
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cntrev = 0;
        for (int i=0; i<n; i++){
            for (int j = i+1; j< n; j++){
                if (nums[i] > (long long)2 * nums[j]) cntrev++;
            }
        }
        return cntrev;
    }
};

// Optimal
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums,0,n-1);
    }
    
    int mergesort(vector <int> & nums, int low, int high){
        int cntrev = 0;
        if (low == high) return cntrev;
        int mid = (low + high)/2;
        cntrev += mergesort(nums,low, mid);
        cntrev += mergesort(nums,mid+1, high);
        cntrev += check(nums, low, mid, high);
        cntrev += merge(nums, low, mid, high);
        return cntrev;
    }

    int check(vector <int> &nums, int low, int mid, int high){
        int cnt = 0;
        int right = mid +1;
        for (int i =low ; i <= mid; i++){
            while (right <= high && nums[i] > (long long)2*nums[right]) {
                right++;
            }
            cnt += right - (mid+1);
        }
        return cnt;
    }

    int merge(vector <int> & nums, int low, int mid, int high){
        int cnt = 0;
        int left = low; 
        int right = mid+1;
        vector <int> temp ;
        while (left <= mid && right <= high){
            if (nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++){
            nums[i] = temp[i-low];
        }
        return cnt;
    }
};