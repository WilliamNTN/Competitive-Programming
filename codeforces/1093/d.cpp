#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
LL mod = 998244353;
LL t,n,m,set1,set2;
LL color[maxN];
vector<LL> graph[maxN];
LL powMod(LL base, LL exp){
	LL ans = 1;
	for(LL i = 0; i < exp; i++){
		ans = ((ans%mod)*(base%mod))%mod;
	}
	return ans;
}


bool isOk(LL v){

	if(color[v] == 0) set2++;
		else set1++;

	for(LL i = 0; i < graph[v].size(); i++){
		LL u = graph[v][i];
		if(color[u] == -1){
			color[u] = 1-color[v]; // 1<->0
			if(!isOk(u)) return false;
		}
		else if(color[u] == color[v]) return false;
	}

	return true;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 0; i < n; i++){
			graph[i].clear();
			color[i] = -1;
		}
		for(LL i = 0; i < m; i++){
			LL u,v;
			cin>>u>>v;
			u--;v--;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		LL ans = 1;
		bool flag = true;
		for(int i = 0; i < n; i++){
			if(color[i] != -1) continue;
			set1 = set2 = 0;
			color[i] = 1;
			if(isOk(i)){
				ans = (ans * ((powMod(2,set1) + powMod(2,set2))%mod))%mod;
			}else{
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<ans<<endl;
		}else
			cout<<0<<endl;
		
	}
	return 0;
}
