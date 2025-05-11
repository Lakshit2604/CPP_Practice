# include <iostream>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r){
    vector<int> temp;
    int left = l;
    int right = mid+1;
    while (left<= mid && right <= r){
        if(arr[left] <= arr[right]) {
            temp.emplace_back(arr[left]);
            left++;
        }
        else{
            temp.emplace_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.emplace_back(arr[left]);
        left++; 
    }
    while(right <= r){
        temp.emplace_back(arr[right]);
        right++;
    }
    for (int i = l; i <=r; i++){
        arr[i] = temp[i-l];
    }
}
void mergeSort(vector<int> &arr, int l, int r) {
    // code here
    if(l==r) return;
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}


int main(){          // 0  1  2  3  4
    vector <int> arr = {4, 1, 3, 9, 7};
    mergeSort(arr, 0, 4);
    for (int i : arr){
        cout << i << ' ';
    }
}