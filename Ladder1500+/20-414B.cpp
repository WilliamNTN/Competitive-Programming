#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,k;

LL mat[2123][2123];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;

	
	for(LL i = 1; i<=n; i++){
		mat[1][i] = 1;
	}


	for(LL kk = 1; kk < k; kk++){
		for(LL i = 1; i<=n; i++){
			for(LL j = i; j<=n; j+=i){
				mat[kk+1][j] += mat[kk][i];
			}
		}
	}

	LL final = 0;
	for(LL i = 1; i<=n; i++){
		final+=mat[k][i];
		final = final % (LL)(pow(10,9)+7);
	}

	cout<<final<<endl;


	return 0;
}
