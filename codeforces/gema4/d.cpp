#include <bits/stdc++.h>
using namespace std;

long long int n;
long double p;

#define LL long long int
int main(){

	cin>>n>>p;

	if(p == 0){
		cout<<0.0000<<endl;
		return 0;
	}

	if(p == 1){
		cout<<1.0000<<endl;
		return 0;
	}
	
	long double total = 0;

	LL bob = 2;

	long double initial = p;
	total+=initial;
	long double factor = p * (1.0-p);

	while(bob <= round(n/2.0)){
		initial *= factor;
		total += initial;
		bob++;
	}


	cout<<fixed<<setprecision(4);
	cout<<total<<endl;


}