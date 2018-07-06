#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n,q;
LL vals[201234];
LL occ[201234];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>q;

	for(LL i=1; i<=n; i++) cin>>vals[i];

	while(q--){
		LL l,r;
		cin>>l>>r;
		occ[l]++;
		if(r <= n-1) occ[r+1]--;
	}
	LL sum = 0;
	for(LL i=1;i<=n;i++){
		sum += occ[i];
		occ[i] = sum;
	}

	sort(vals+1,vals+n+1);
	sort(occ+1,occ+n+1);

	sum = 0;
	for(LL i=1; i<=n;i++)
		sum += vals[i] * occ[i];
	cout<<sum<<endl;
	return 0;
}
