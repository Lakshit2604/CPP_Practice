# include <iostream>
# include <string>
# include <cctype>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        rev(0,arr);
    }
    void rev(int i, vector<int> &arr){
        if (i>=arr.size()/2) return;
        swap(arr[i],arr[arr.size()-i-1]);
        rev(i+1, arr);
    }
};

