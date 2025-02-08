# include <iostream>
using namespace std;
bool isPrime(int n)
{
	// Write your code here.
	int count=0;
	for (int i = 1; i <= sqrt(n); i++){
		    if(n%i==0){
			    if(i!=n/i){
				    count+=2;
			    }
			else {count+=1;}
		    }
	}
	return(count==2);
}
