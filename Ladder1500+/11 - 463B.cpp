#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n;
LL piles[1012345];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	piles[0] = 0;

	LL low = 101234;
	LL acc = 0;
	for(int i = 1; i<=n; i++){
		cin>>piles[i];
		acc += (piles[i-1] - piles[i]);
		if(acc < low)
			low = acc;
	}

	if(low < 0)
		cout<<abs(low)<<endl;
	else
		cout<<0<<endl;
	return 0;
}
