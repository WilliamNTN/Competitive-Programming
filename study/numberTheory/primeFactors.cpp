#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n;


void primeFactors(LL x){
	while(x%2 == 0){
		cout<<"2 ";
		x = x/2;
	}

	for(int i = 3; i <= sqrt(x); i+=2){
		
		while(x % i == 0){
			cout<<i<<" ";
			 x = x/i;
		}
	}

	if(n > 2)
		cout<<n<<" ";

	cout<<endl;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	primeFactors(n);

	return 0;
}
