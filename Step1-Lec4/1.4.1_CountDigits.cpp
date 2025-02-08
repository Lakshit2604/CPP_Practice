# include <iostream>
using namespace std;   
int main(){
    int n = 312;
	vector<int> arr;
	string num = to_string(n);  // now element is not integer it is now char
	for(int i = 0; i < num.length(); i++){
        int digit = num[i] - '0';
		if ( digit >0 && n % digit  == 0){
			arr.emplace_back(digit);
		}
	}
	int count = arr.size();
    cout << count;
	return 0;
}
