# include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    vector <int> arr = {10,5,10,15,10,5};
    unordered_map <int, int > mpp;
    for (int i =0; i < arr.size(); i++){
        mpp[arr[i]]++;
    }
    for (auto i : mpp){
        cout << i.first << "->" << i.second << '\n'; 
    }
    
    return 0;
}