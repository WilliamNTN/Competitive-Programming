#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int a,b,c;
int n;
int dp[4040];

int solve(int x){
	if(x == 0) return 0;
	if(x < 0) return -0x3f3f3f3f;

	if(dp[x] != -1) return dp[x];

	return dp[x] = max(max(solve(x-a),solve(x-b)),solve(x-c)) + 1;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>a>>b>>c;
	memset(dp,-1,sizeof(dp));
	cout<<solve(n)<<endl;
	return 0;
}
