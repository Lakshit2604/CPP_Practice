 # include <iostream>
 # include <vector>
 using namespace std;
 
 // Brute 
 class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int right = 0;
        vector <int> merge;
        while (left < nums1.size() && right < nums2.size()){
            if (nums1[left] < nums2[right]) {
                merge.push_back(nums1[left]);
                left++;
            }
            else {
                merge.push_back(nums2[right]);
                right++;
            }
        }
        while (left < nums1.size()){
            merge.push_back(nums1[left]);
            left++;
        }
        while(right < nums2.size()){
            merge.push_back(nums2[right]);
            right++;
        }
        int n = merge.size();
        if (n % 2 == 0){
            return (double)(merge[n/2] + merge[(n/2)-1])/2.0;
        }
        return (double)merge[(n-1)/2];
    }
};

// Better
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ind1 = (n1+n2)/2 - 1;
        int ind2 = (n1+n2)/2;
        int ind = 0;
        int ele1 = -1;
        int ele2 = -1;
        int left = 0;
        int right = 0;
        while (left < nums1.size() && right < nums2.size()){
            if (nums1[left] <= nums2[right]) {
                if (ind == ind1){
                    ele1 = nums1[left];
                }
                else if (ind == ind2){
                    ele2 = nums1[left];
                    break;
                }
                ind++;
                left++;
            }
            else {
                if (ind == ind1){
                    ele1 = nums2[right];
                }
                else if (ind == ind2){
                    ele2 = nums2[right];
                }
                ind++;
                right++;
            }
        }
        while (left < nums1.size()){
            if (ind == ind1){
                ele1 = nums1[left];
            }
            else if (ind == ind2){
                ele2 = nums1[left];
            }
            ind++;
            left++;
        }
        while(right < nums2.size()){
            if (ind == ind1){
                ele1 = nums2[right];
            }
            else if (ind == ind2){
                ele2 = nums2[right];
            }
            ind++;
            right++;
        }

        if ((n1+n2) % 2 == 0){
            return (double)(ele1 + ele2)/2.0;
        }
        return (double)ele2;
    }
};

// Optimal
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int n3 = n1 + n2;
        int low = 0;
        int high = n1;
        int left = (n3 + 1)/2;
        while(low <= high){
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 -1];
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (l1 <= r2 && l2 <= r1){
                if (n3 % 2 == 0) return (max(l1,l2)+ min(r1,r2))/2.0;
                else return (double)max(l1,l2);
            }
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0.0;
    }
};

int main()
{   Solution sol;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout <<  sol.findMedianSortedArrays(a, b) << '\n';
}
