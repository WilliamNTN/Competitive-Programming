
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 2020;
LL mod = 1000000007;
LL n,k;
LL dp[maxN][maxN];


LL solve(LL position, LL lastValue){
	if(position == k) return 1;

	LL mult = n/lastValue;
	if(dp[position][mult] != -1)
		return dp[position][mult];

	LL ans = 0;

	for(LL i = lastValue; i <= n; i+=lastValue){
		ans  = (ans + solve(position+1,i)%mod)%mod;
	}

	return dp[position][mult] = ans%mod;

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,1)%mod<<endl;
	return 0;
}
