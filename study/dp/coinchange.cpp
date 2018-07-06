#include <bits/stdc++.h>
using namespace std;

int change,n;
int coins[1010];
int dp[1010][1010];
int totalCount;
int solve(int val, int minIndex){
	if(val == 0) return 1;
	if(val < 0) return 0;
	if(minIndex >= n) return 0;

	if(dp[val][minIndex] != -1) return dp[val][minIndex];

	return dp[val][minIndex] = solve(val,minIndex+1) + solve(val-coins[minIndex],minIndex);
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	memset(dp,-1,sizeof(dp));
	cin>>change>>n;
	for(int i=0; i<n; i++) cin>>coins[i];

	sort(coins,coins+n);
	totalCount = 0;
	cout<<solve(change,0)<<endl;
	return 0;
}
