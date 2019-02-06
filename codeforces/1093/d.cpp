
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
LL n,m;
LL t;
LL color1, color0;
LL colors[maxN];
LL mod = 998244353;
vector<LL> graph[maxN];
/*
bool bfs(vector<LL> graph[maxN],LL start){

	queue<LL> q;
	q.push(start);
	colors[start] = 0;

	while(q.size()){
		LL u = q.front(); q.pop();
		if(colors[u] == 0) color0++;
		else color1++;

		for(LL i = 0; i < graph[u].size(); i++){
			LL v = graph[u][i];
			if(colors[v] == colors[u]) return false;
			if(colors[v] == -1) q.push(v);
			colors[v] = 1 - colors[u];
		}
	}

	return true;
}
*/


bool dfs(LL v, LL c){
	colors[v] = c;
	if(c == 1) color1++;
	else color0++;

	for(LL i = 0; i < graph[v].size(); i++){
		LL to = graph[v][i];
		if(colors[to] == -1){
			if(!dfs(to,1-c)) return false;
		}else if(colors[to] == c) return false;
	}

	return true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		cin>>n>>m;

		for(LL i = 0; i < n; i++)
			graph[i].clear();

		for(LL i = 0; i < m; i++){
			LL u,v;
			cin>>u>>v; u--; v--;
			graph[u].pb(v);
			graph[v].pb(u);
		}

		memset(colors,-1,sizeof(colors));
		LL ans = 1;
		for(LL i = 0; i < n; i++){ // O(v+e)
			if(colors[i] == -1){
				color0 = color1 = 0;
				colors[i] = 0;
				if(!dfs(i,0)) ans = 0;
				else{
					ans = (ans * ((LL)(pow(2,color0) + pow(2,color1)))%mod)%mod;
				}
			}
		}

		cout<<ans<<endl;

	}
	return 0;
}
