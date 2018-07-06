#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,sum;
int vals[1012];
LL total;
int dp[1012][1012];

bool solve(int pos, int tsum){
		if(tsum == 0) return true;
		if(pos == n && tsum != 0) return false;

		if(dp[pos][tsum] != -1) return dp[pos][tsum];

		total++;
		if(vals[pos] > tsum) return dp[pos][tsum] = solve(pos+1,tsum);

		return dp[pos][tsum] = (solve(pos+1,tsum) || solve(pos+1,tsum-vals[pos]));
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>sum;
	for(int i=0;i<n;i++) cin>>vals[i];
	total = 0;
	if(solve(0,sum)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
