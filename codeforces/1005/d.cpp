
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 202134;
string s;
LL dp[maxN][3];

LL solve(LL position, LL mod){
	if(position == s.size()) return 0;
	mod = (mod + (s[position]-'0')%3)%3;
	if(dp[position][mod] != -1)
	    return dp[position][mod];
	if(mod == 0)
		return dp[position][mod] = 1 + solve(position+1,0);
	return dp[position][mod] = max(solve(position+1,mod),solve(position+1,0));
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0)<<endl;
	return 0;
}
