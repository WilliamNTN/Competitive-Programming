#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n;
LL dp[100];
LL catalan(LL x){
    
    for(LL i = 2; i<=n; i++){

    	dp[i] = 0;
    	for(LL j = 0; j<i; j++){
    		dp[i] += dp[j]*dp[i-j-1];
    	}
    }

    return dp[x];
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	dp[0] = dp[1] = 1;
	for(LL i = 0; i<=n; i++)
		cout<<catalan(i)<<" ";
	cout<<endl;

	return 0;
}
