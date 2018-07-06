#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n;
LL vals[101234];
LL dp[101234];



LL solve(LL pos){

	if(pos >=(n-1)) return 0;

	if(dp[pos] != -1)
		return dp[pos];

	LL temp = 0x3f3f3f3f;

	for(LL i = vals[pos]; i>=1; i--){
		
		temp = min(temp,solve(pos+i)+1);
	}


	return dp[pos] = temp;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<(n-1);i++) cin>>vals[i];

	memset(dp,-1,sizeof(dp));

	cout<<solve(0)<<endl;

	return 0;
}
