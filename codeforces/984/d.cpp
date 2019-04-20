#include <bits/stdc++.h>
using namespace std;

int n,q,l,r;

int vals[5050];
int dp[5050][5050];


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>vals[i];
		dp[0][i] = vals[i];
	}


	for(int i=1; i<n; i++){
		for(int j=0; j<= (n-i); j++){
			dp[i][j] = dp[i-1][j+1] ^ dp[i-1][j];
		}
	}

	for(int i=1;i<n;i++){
		for(int j=0; j< n-i; j++){
			dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i-1][j+1]});
		}
	}

	cin>>q;
	while(q--){
		cin>>l>>r;
		int len = r-l;
		l--;
		cout<<dp[len][l]<<endl;
	}
	return 0;
}
