#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n, w;
LL vals[1010];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>w;
	for(LL i=0;i<n;i++) cin>>vals[i];

	LL max = 0;
	LL min = 0;
	LL actual = 0;

	for(LL i=0; i<n; i++){
		actual += vals[i];
		if(actual > max)
			max = actual;
		else if(actual < min)
			min = actual;
	}

	LL ul = w - max + 1;
	LL ll = 0 - min;
	LL to = ul - ll;

	if(to <= 0)
		cout<<0<<endl;
	else
		cout<<to<<endl;
	return 0;
}
