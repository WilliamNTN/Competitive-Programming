#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define key pair<pair<int,int>,int>
LL n;
string s;
map<key,LL> results;


key makeKey(LL pos, LL pu, LL cost){
	return make_pair(make_pair(pos,pu),cost);
}


LL solve(LL pos, LL pu, LL cost){

	if(s[pos] == '.'){
		return -1;
	}

	if(pos >= n){
		return cost;
	}
	if(results[makeKey(pos,pu,cost)])
		return results[makeKey(pos,pu,cost)];

	if(s[pos] == 'x'){
		LL res = solve(pos+1,pu,cost+1);
		results[makeKey(pos,pu,cost)] = res;
		return res;
	}

	if(s[pos] == 'p'){
		LL ret1 = solve(pos+1,pu,cost+1);
		LL ret2 = solve(pos+1+pu,pu*2,cost+1);
		LL ret;
		if(ret2 == -1){
			ret =  solve(pos+1,pu,cost+1);
		}
		else if(ret1 == -1){
			ret = solve(pos+1+pu,pu*2,cost+1);
		}

		else if(ret1 < ret2){
			ret =  solve(pos+1,pu,cost+1);
		}

		else{
			ret =  solve(pos+1+pu,pu*2,cost+1);
		}

		results[makeKey(pos,pu,cost)] = ret;
		return ret;
	}

}
	
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;

	cout<<solve(0,2,0)<<endl;

	return 0;
}
	