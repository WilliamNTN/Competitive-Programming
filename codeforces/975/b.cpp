#include <bits/stdc++.h>
using namespace std;
#define LL long long int


LL stones[14];


LL solve(LL pos){
	if(stones[pos] == 0) return 0;
	LL st[14];
	for(LL i = 0; i<14; i++)
		st[i] = stones[i];

	LL x = st[pos];
	st[pos] = 0;

	LL each = x/14;

	for(LL i = 0; i<14; i++)
		st[i] += each;

	x = x - (each*14);
	LL t = (pos+1)%14;
	while(x--){
		st[t]++;
		t = (t+1)%14;
	}

	LL s = 0;
	for(LL i = 0; i<14; i++)
		if(st[i]%2 == 0)
			s += st[i];
	return s;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	for(LL i = 0; i<14; i++)
		cin>>stones[i];
	LL ans = 0;
	for(LL i =0; i<14; i++){
		ans = max(ans,solve(i));
	}

	cout<<ans<<endl;
	return 0;
}
