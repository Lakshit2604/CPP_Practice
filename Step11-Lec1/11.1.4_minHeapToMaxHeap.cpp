# include <iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        int parent = (N-1)/2;
        while (parent >= 0){
            int currInd = parent;
            while (true){
                int maxInd = currInd;
                int lChild = 2*currInd + 1;
                int rChild = 2*currInd + 2;
                if ( lChild < N && arr[lChild] > arr[maxInd]) maxInd = lChild;
                if ( rChild < N && arr[rChild] > arr[maxInd]) maxInd = rChild;
                if ( maxInd == currInd) break;
                swap(arr[currInd], arr[maxInd]);
                currInd = maxInd;
            }
            parent--;
        }
    }
};
