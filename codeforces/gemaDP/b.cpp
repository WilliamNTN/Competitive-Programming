#include <bits/stdc++.h>
using namespace std;

string a,b;
int dp[1010][1010];

int solve(int i, int j){

	if(i == a.size() || j == b.size()) return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	if(a[i] == b[j])
		return dp[i][j] = solve(i+1,j+1)+1;

	return dp[i][j] = max(solve(i+1,j),solve(i,j+1));
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp,-1,sizeof(dp));

	cin>>a>>b;

	cout<<solve(0,0)<<endl;



	return 0;
}
