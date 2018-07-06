#include <bits/stdc++.h>
using namespace std;

int n;
int vals[101234];
int dp[101234];


int solve(int pos){
	if(pos >= (n-1))
		return 0;

	if(dp[pos] != -1)
		return dp[pos];

	int temp = 0x3f3f3f3f;
	
	for(int i=vals[pos]; i>=1; i--){
		if(dp[pos+i] != -1)
			temp = min(temp,dp[pos+i]+1);
		
		else
			temp = min(temp,solve(pos+i)+1);
	}
	return dp[pos] = temp;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	memset(dp,-1,sizeof(dp));

	cin>>n;
	for(int i=0; i<(n-1); i++)
		cin>>vals[i];


	// for(int i=(n-2); i>=0; i--)
	// 	solve(i);
	cout<<solve(0)<<endl;
	//cout<<dp[0]<<endl;
	return 0;
}
