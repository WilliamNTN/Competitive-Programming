#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,k;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;

	LL p[n];
	for(LL i=1; i<=n; i++)
		p[i-1] = i;

	LL print = n;
	for(LL i=0; i<k; i++){
		cout<<print--<<" ";
	}

	print = 1;
	for(LL i=k; i<n; i++)
		cout<<print++<<" ";
	cout<<endl;

	return 0;
}
