#include <bits/stdc++.h>
using namespace std;

#define LL long long int

bool greaterS(const LL &a, const LL &b){
	return a > b;
}

LL n;
LL coins[112];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	for(LL i=0;i<n;i++)
		cin>>coins[i];

	sort(coins,coins+n,greaterS);

	for(LL i=1; i<n; i++)
		coins[i] += coins[i-1];
    LL i;
	for(i = 0; (coins[i] <= (coins[n-1]-coins[i])); i++);

	cout<<i+1<<endl;
	return 0;
}
