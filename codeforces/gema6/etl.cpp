#include <bits/stdc++.h>
using namespace std;

#define LL long long int
LL n,q;
int vals[10123];
LL sums[10123];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>q;
	for(LL i=0;i<n;i++){			// n;
		cin>>vals[i];
	}
	while(q--){
		int sums[10123];
		LL a,b;
		cin>>a>>b; a--; b--;
		int intervalS = (b-a+1);
		copy(vals+a,vals+a+intervalS,sums);
		int c = 0;
		for(LL size = 2; size <= intervalS; size++){
			for(LL i = 0; i <=(intervalS-size); i++){
				sums[i] = sums[i] + vals[i+size-1+a];
				if(sums[i] == 0)
					c++;
			}
		}

		cout<<c<<endl;
	}
	return 0;
}