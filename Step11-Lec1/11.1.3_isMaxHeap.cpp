# include <iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        int parent = (n-1)/2;
        while (parent >= 0){
            int lChild = 2* parent + 1;
            int rChild = 2 * parent + 2;
            if ( lChild < n && arr[parent] < arr[lChild]) return false;
            if ( rChild < n && arr[parent] < arr[rChild]) return false;
            parent--;
        }
        return true;
    }
};