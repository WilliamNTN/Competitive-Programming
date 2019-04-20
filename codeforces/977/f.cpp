#include <bits/stdc++.h>
using namespace std;

#define LL long long int
map<LL,LL> dp;
map<LL,LL> pos;
int n;
LL vals[201234];
int lastValue, mmax, pr;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	mmax = 0; lastValue = 0;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>vals[i];
		dp[vals[i]] = dp[vals[i]-1] + 1;
		if(mmax < dp[vals[i]]){
			mmax = dp[vals[i]];
			lastValue = vals[i];
		}
	}

	cout<<mmax<<endl;
	pr = lastValue - mmax + 1;
	for(int i=1; i<=n; i++){
		if(vals[i] == pr){
			cout<<i<<" ";
			pr++;
		}
	}

	cout<<endl;
	return 0;
}
