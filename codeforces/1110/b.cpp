
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
LL n,m,k;
LL vals[maxN];

int dp[maxN][2];


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
	}

	cout<<solve(0,k)<<endl;
	return 0;
}
