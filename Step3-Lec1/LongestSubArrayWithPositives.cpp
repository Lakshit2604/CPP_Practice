# include <iostream>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    long long left =0 ; 
    long long right =0; 
    long long maxLen =0;
    long long sum =0;
    long long n = a.size();
    while(right<n){
        sum += a[right];
        while (sum > k && left <= right){
            sum -= a[left];
            left++;
        }
        if(sum == k ){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}