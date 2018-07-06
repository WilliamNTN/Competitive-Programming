#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n;
string s;
map<pair<int,int>,int> dp;

int solve(int pos, int pu){
	if(pos >= n) return 0;

	if(dp[make_pair(pos,pu)] != 0)
		return dp[make_pair(pos,pu)];

	if(s[pos] == '.')
		return dp[make_pair(pos,pu)] = 0x3f3f3f3f;
	if(s[pos] == 'x')
		return dp[make_pair(pos,pu)] =  solve(pos+1,pu)+1;

	return dp[make_pair(pos,pu)] =  min(solve(pos+1,pu)+1, solve(pos+(pu+1),pu*2)+1);
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	int res = solve(0,2);

	if(res >= 0x3f3f3f3f) cout<<-1<<endl;
	else cout<<res<<endl;
	
	return 0;
}
