#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n;
LL size[3030];
LL price[3030];

LL dp[3030][3][3030];

LL solve(int pos, int ndisplay, LL lastUsed){
	if(pos > n){
		if(ndisplay == 0) return 0;
		return 0x3f3f3f3f;
	}
	if(ndisplay == 0) return 0;

	if(dp[pos][ndisplay][lastUsed] != -1)
		return dp[pos][ndisplay][lastUsed];

	LL ans = 0x3f3f3f3f;

	if(size[pos] > size[lastUsed]){
		ans = min(ans, solve(pos+1,ndisplay-1,pos) + price[pos]);
	}
	ans = min (ans, solve(pos+1,ndisplay,lastUsed));

	return dp[pos][ndisplay][lastUsed] = ans;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=1; i<=n; i++) cin>>size[i];
	for(int i=1; i<=n; i++) cin>>price[i];
	
	memset(dp,-1,sizeof(dp));
	size[0] = price[0] = 0;
	LL res = solve(1,3,0);

	if(res >= 0x3f3f3f3f) cout<<-1<<endl;
	else cout<<res<<endl;

	return 0;
}
