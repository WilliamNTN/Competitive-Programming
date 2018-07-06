#include <bits/stdc++.h>
using namespace std;

int n,q,l,r,len;
int vals[5050];
int dp[5050][5050];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>vals[i];
		dp[0][i] = vals[i];
	}
	
	for(int i = 1; i<n;i++){
		for(int j=0; j<(n-i); j++){
			dp[i][j] = dp[i-1][j] + dp[0][j+i];
		}
	}
	for(int i=0; i<n; i++){
		dp[0][i] = 0;
	}

	for(int i=0; i<n; i++){
		dp[1][i] = dp[1][i] == 0? 1 : 0;
	}

	for(int i=2; i<n; i++){
		for(int j=0; j<(n-i);j++){
			dp[i][j] = dp[i][j] == 0? 1: 0;
			dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i-1][j+1] - dp[i-2][j+1];
		}
	}
	while(q--){
		cin>>l>>r;
		len = r-l;
		l--;
		cout<<dp[len][l]<<endl;
	}
	return 0;
}
