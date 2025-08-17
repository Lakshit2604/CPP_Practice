# include <iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = sumArr(arr);
        if (n < k) return -1;
        while ( low <= high){
            int mid = low + (high - low)/2;
            if (stud(arr, mid) <= k ) high = mid - 1;
            else low = mid + 1;
        }
        return low ;
    }
    
    int sumArr(vector <int> &arr){
        int sum = 0;
        for (int i = 0; i< arr.size(); i++){
            sum += arr[i];
        }
        return sum;
    }
    
    int stud(vector <int> &arr, int pages){
        int sum = arr[0];
        int stud = 1;
        for (int i = 1; i < arr.size(); i++){
            if ((sum + arr[i]) <= pages) sum += arr[i];
            else sum = arr[i], stud++;
        }
        return stud;
    }
};

int main(){
    Solution sol;
    vector <int> arr = {15, 10, 19, 10, 5, 18, 7};
    cout << sol.findPages(arr, 5);
    return 0;
}