#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
int n,m,u,v;
vector<int> graph[maxN];
vector<pii> entry;
int colors[maxN];

bool bipartite(int s){
	colors[s] = 0;
	queue<int> q;
	q.push(s);

	while(q.size()){
		int u = q.front(); q.pop();
		for(int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i];
			if(colors[v] == -1){
				colors[v] = 1 - colors[u];
				q.push(v);
			}else if(colors[v] == colors[u]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i = 0; i < m; i++){
		cin>>u>>v;
		entry.pb(mp(u,v));
		graph[u].pb(v);
		graph[v].pb(u);
	}
	memset(colors,-1,sizeof(colors));
	if(bipartite(1)){
		cout<<"YES"<<endl;
		for(int i = 0; i < m; i++){
			if(colors[entry[i].ff] == 0)
				cout<<0;
			else
				cout<<1;
		}
		cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
