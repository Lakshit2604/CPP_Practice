# include <iostream>
using namespace std;

class Solution {
    public:
      // Function to sort the array using bubble sort algorithm.
      void bubbleSort(vector<int>& arr) {
          // Your code here
           int len = arr.size();
           RecBubble(arr, len);
      }
      void RecBubble(vector <int> &arr, int len){
          int swap = 0;
          if (len-1 == 0) return;
          for(int i = 0 ; i <= (len-2) ; i++){
              if ( arr[i] > arr[i+1]){
                  int temp = arr[i];
                  arr[i] = arr[i+1];
                  arr[i+1] = temp;
                  swap +=1;
               }
          }
          if(swap == 0) return;
          RecBubble(arr,len-1 );
      }
  };