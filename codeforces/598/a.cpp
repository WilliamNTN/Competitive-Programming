#include <iostream>
#include <math.h>
using namespace std;


long long int wsum(int num){
	long long int somaTotal = num*(num+1.0)/2.0;
	int n = log2(num);
	long long int somaExp = pow(2,n+1)-1;

	return(somaTotal - 2.0 * somaExp);

}

int main(){
	int n,count=0,num;
	cin >> n;

	while(count < n){
		count++;
		cin >> num;
		cout<<wsum(num)<<endl;
	}

	return 0;
}