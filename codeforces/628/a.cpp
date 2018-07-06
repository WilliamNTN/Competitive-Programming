#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,b,p;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>b>>p;
	LL bByGame = b*2 + 1;
	LL towels = p*n;

	LL bottles = 0;
	while(n > 1){
		LL num = log2(n);
		bottles += num*bByGame;
		n -= num;
	}

	cout<<bottles<<" "<<towels<<endl;
	return 0;
}
