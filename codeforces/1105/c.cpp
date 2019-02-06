
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL n;
LL l,r;
LL mod = pow(10,9) + 7;

LL dp[maxN][3];

LL count(){



	int mods[3] = {0,0,0};
	mods[l%3] = (r-l)/3 + 1;
	if((r-l)>0) mods[(l+1)%3] = (r-(l+1))/3 + 1;
	if((r-l)>1) mods[(l+2)%3] = (r-(l+2))/3 + 1;

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;


	int mults[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			mults[i][j] = mods[(3+j-i)%3];
		}
	}
	for(int i = 1; i <=n; i++){
		for(int m = 0; m < 3; m++){
			for(int mm = 0; m < 3; m++){
				dp[i][m] += (dp[i-1][mm] * mults[mm][m])%mod;
			}
		}	
	}

	return (dp[n][0]%mod + dp[n][1]%mod + dp[n][2]%mod)%mod;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	memset(dp,0,sizeof(dp));
	cin>>n>>l>>r;
	cout<<count()%mod<<endl;
	return 0;
}
