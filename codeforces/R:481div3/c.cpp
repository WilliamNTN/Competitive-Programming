#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,m;
LL dorms[211234];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	for(LL i=0; i<n; i++)
		cin>>dorms[i];

	LL actualSum = 0;
	LL actualI = 0;
	while(m--){
		LL val;
		cin>>val;

		val -= actualSum;

		LL i;
		for(i=actualI; i<n; i++){
			if(val >= dorms[i]){
				val-=dorms[i];
				if(val == 0)
					break;
			}
			else
				break;
		}

		for(LL aux = actualI; aux < i; aux++)
			actualSum += dorms[aux];
		actualI = i;

		if(val == 0)
			val = dorms[i];

		cout<<i+1<<" "<<val<<endl;
	}
	return 0;
}
