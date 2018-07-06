#include <bits/stdc++.h>
using namespace std;

#define LL long long int


string a,b;

LL total;
int dp[1010][1010];

int solve(int i, int j){
	if(i < 0) return j+1;
	if(j < 0) return i+1;

	if(dp[i][j] != -1)
		return dp[i][j];

	total++;
	if(a[i] == b[j])
		return dp[i][j] = solve(i-1,j-1);

	return dp[i][j] = 1 + min(solve(i-1,j-1),min(solve(i-1,j),solve(i,j-1)));

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp,-1,sizeof(dp));
	cin>>a>>b;
	total = 0;
	cout<<solve(a.size()-1,b.size()-1)<<endl;
	return 0;
}
