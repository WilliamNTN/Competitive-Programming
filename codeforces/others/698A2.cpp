#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n;
int vals[maxN];
int dp[maxN][3];

int solve(int pos, int last){// 0->rest, 1-> 1, 2-> 2

	if(pos >= n){
		return 0;
	}

	if(dp[pos][last] != -1)
		return dp[pos][last];

	if(vals[pos] == 0){
		return dp[pos][last] = solve(pos+1,0)+1;
	}
	if(vals[pos] == 1){
		if(last == 1)
			return dp[pos][last] = solve(pos+1,0)+1;
		return dp[pos][last] =  solve(pos+1,1);
	}
	if(vals[pos] == 2){
		if(last == 2)
			return dp[pos][last] =  solve(pos+1,0)+1;
		return dp[pos][last] =  solve(pos+1,2);
	}

	int a,b;
	a = b = INT_MAX;

	if(last != 1)
		a = solve(pos+1,1);
	if(last != 2)
		b = solve(pos+1,2);

	return dp[pos][last] = min(a,b);
}

	
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	cout<<solve(0,0)<<endl;
	return 0;
}
	