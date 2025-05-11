# include <iostream>
# include <vector>
# include <map>
using namespace std;

// Brute
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int left = 0;
            int right = 0;
            vector <int> temp;
            while (left < m && right < n){
                if (nums1[left] < nums2[right]) temp.emplace_back(nums1[left++]);
                else temp.emplace_back(nums2[right++]);
            }
            while (left < m){
                temp.emplace_back(nums1[left++]);
            }
            while (right < n){
                temp.emplace_back(nums2[right++]);
            }
            for (int i = 0; i < (m+n) ; i++){
                nums1[i] = temp[i];
            }
        }
    };

// Optimal by change according to question
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1, right = n-1, index = m+n-1;
        while(left >= 0 && right >= 0){
            if (nums1[left] <= nums2[right]){
                nums1[index] = nums2[right];
                index--;
                right--;
            }
            else{
                nums1[index] = nums1[left];
                index--;
                left--;
            }
        }
        while (right >= 0){ 
            nums1[index] = nums2[right];
            index--; 
            right--;
        }
        }
    };

// Optimal by swap numbers
// arr1 = {2,5,6} arr2 = {1,4,8}
// result : arr1  = {1,2,4} arr2 = {5,6,8}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = m-1, right = 0;
    while(left >= 0 && right < n){
        if (nums1[left] > nums2[right]) {
            swap(nums1[left--], nums2[right++]);
        }
        else break;
    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(), nums2.end());
}

// Opimal by Gap method
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = m + n;
    int gap = (len/2) + (len%2);
    while (gap > 0){
        int left = 0;
        int right = gap;
        while (right < len){
            if (left < m && right >= m){
                if (nums1[left] > nums2[right-m]) swap(nums1[left], nums2[right-m]);
            }
            else if (left < m && right < m){
                if (nums1[left] > nums1[right]) swap(nums1[left], nums1[right]);
            }
            else {
                if (nums2[left-m] > nums2[right-m]) swap(nums2[left-m], nums2[right-m]);
            }
            left++;
            right++;
        }
        if (gap == 1) break;
        gap = (gap/2) + (gap%2);
    }
}

int main(){
    vector <int> arr1 = {2,5,6};
    vector <int> arr2 = {1,4,8};
    merge(arr1, 3, arr2, 3);
    for (auto it : arr2){
        cout << it << ' ';
    }
    return 0;
}