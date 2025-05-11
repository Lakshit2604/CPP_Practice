# include <iostream>
using namespace std;


int partition(vector<int>& arr, int low, int high) {
    // code here
    // Taking pivot as last element.
    int pivot = arr[high];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<pivot && i<= high-1){
            i++;
        }
        while(arr[j]>=pivot && j>= low+1){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i];
    arr[i] = pivot;
    arr[high] = temp;
    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    // code here
    if(low < high){
        int pIndex = partition(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}
int main(){           
    vector <int> arr = {24 ,18, 38 ,43 ,14 ,40, 1, 54};  //{1,14,18,24, 38,40.43,54}
    quickSort(arr,0,arr.size()-1);
    for (int i : arr){
        cout << i << " ";
    }
    return 0 ;
}