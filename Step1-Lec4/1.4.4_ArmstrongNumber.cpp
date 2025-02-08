# include <iostream>
using namespace std;

bool checkArmstrong(int n){
	string str = to_string(n);
	int cnt = str.size();
	int dup = n;
	int sum = 0;
	while (dup!=0){
		int ld = dup % 10;
		dup /= 10;
		sum += pow(ld,cnt);
	}
	return (n == sum);
}