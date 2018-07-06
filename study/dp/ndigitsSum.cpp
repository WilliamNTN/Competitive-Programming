#include <bits/stdc++.h>
using namespace std;


int n,sum;
int dp[1010][1010];

int solve(int nd, int tsum){
	if(nd == 0) return tsum==0?1:0;
	if(tsum == 0) return 1;

	if(dp[nd][tsum] != -1) return dp[nd][tsum];
	int ans = 0;
	for(int i=nd==n?1:0; i<=9; i++){
		if(tsum-i >= 0)
			ans += solve(nd-1,tsum-i);
	}

	return dp[nd][tsum] = ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>sum;

	cout<<solve(n,sum)<<endl;

	return 0;
}
