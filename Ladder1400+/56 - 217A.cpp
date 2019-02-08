
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;

int n;
vector<pii> coords;
vector<pii> rest;
vector<int> graph[maxN];
int visited[maxN];

void bfs(int start){

	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while(q.size()){
		int u = q.front(); q.pop();

		for(int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i];
			if(visited[v] == -1){
				visited[v] = 1;
				q.push(v);
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		int x,y;
		cin>>x>>y;
		coords.pb(mp(x,y));
	}
	
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(coords[i].ff == coords[j].ff || coords[i].ss == coords[j].ss){
				graph[i].pb(j);
				graph[j].pb(i);
			}
		}
	}	

	int ans = 0;
	memset(visited,-1,sizeof(visited));
	for(int i = 0; i < n; i++){
		if(visited[i] == -1){
			ans++;
			bfs(i);
		}
	}

	cout<<ans-1<<endl;
	return 0;
}
