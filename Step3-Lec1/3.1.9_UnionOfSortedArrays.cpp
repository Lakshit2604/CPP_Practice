# include <iostream>
# include <vector>
using namespace std;
class Solution {
    public:
      // a,b : the arrays
      // Function to return a list containing the union of the two arrays.
      vector<int> findUnion(vector<int> &a, vector<int> &b) {
          // Your code here
          // return vector with correct order of elements
          vector <int> result;
          int i =0 ;
          int j = 0;
          int n1 = a.size();
          int n2 = b.size();
          while(i<n1 && j<n2){
              if(a[i] <= b[j]){
                  if(result.size()==0 ||result.back()!=a[i]){
                      result.emplace_back(a[i]);
                  }
                  i++;
              }
              else{
                  if(result.size()==0 ||result.back()!=b[j]){
                      result.emplace_back(b[j]);
                  }
                  j++;
              }
          }
          while(i < n1){
              if(result.size()==0 || result.back()!=a[i])  {
                  result.emplace_back(a[i]);
              }
              i++;
          }
          
          while(j<n2){
              if(result.size()==0 ||result.back()!=b[j]){
                  result.emplace_back(b[j]);
              }
              j++;    
          }
          return result;
      }
  };