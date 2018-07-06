#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n1,n2,k1,k2;

int dp[110][110][11][11];


int solve(int pos, int freef, int freeh, int linef, int lineh){
	if(pos > (n1+n2)){
		if(linef <= k1 && lineh <= k2){
			return 1;
		}
		else return 0;
	}
	if(linef > k1 || lineh > k2) return 0;
	if(freef < 0 || freeh < 0) return 0;

	if(dp[freef][freeh][linef][lineh] != -1)
		return dp[freef][freeh][linef][lineh];

	LL ans = 0;

	if(freef > 0)
		ans += solve(pos+1,freef-1,freeh,linef+1,0) % (LL)pow(10,8);
	if(freeh > 0)
		ans += solve(pos+1,freef,freeh-1,0,lineh+1) % (LL)pow(10,8);

	return dp[freef][freeh][linef][lineh] = (ans % (LL)pow(10,8));
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n1>>n2>>k1>>k2;
	memset(dp,-1,sizeof(dp));
	cout<<solve(1,n1,n2,0,0)<<endl;
	return 0;
}
