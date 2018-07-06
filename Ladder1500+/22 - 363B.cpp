#include <bits/stdc++.h>
using namespace std;

#define LL long long int
LL n,k;
LL vals[1212345];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	vals[0] = 0;

	for(LL i = 1; i<=n; i++)
		cin>>vals[i], vals[i] += vals[i-1];

	LL low = vals[n]*10123;
	LL r = n+1;

	for(LL i = 1; i<=(n-(k-1)); i++){
		if((vals[i+(k-1)] - vals[i-1]) < low){
			low = vals[i+(k-1)] - vals[i-1];
			r = i;
		}
	}

	cout<<r<<endl;

	return 0;
}
