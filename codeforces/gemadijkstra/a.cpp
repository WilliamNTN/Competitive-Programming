#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second

int n,m,a;
vector<int> graph[101234];
vector<int> cost[101234];
int dist[101234];

void dijkstra(int s){
	
	priority_queue<pair<int,int> > pq;

	memset(dist,0x3f3f3f3f,sizeof(dist));

	pq.push(mp(0,s));
	dist[s] = 0;

	while(pq.size()){
		int u = pq.top().se;
		pq.pop();

		for(int i=0; i<graph[u].size(); i++){
			int v = graph[u][i];
			int w = cost[u][i];

			if(dist[v] > dist[u] + w){
				dist[v] = dist[u]+w;

				pq.push(mp(-dist[v],v));
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>a;

	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back(v);
		graph[v].push_back(u);

		cost[u].push_back(w);
		cost[v].push_back(w);
	}

	dijkstra(a);
	for(int i=1; i<=n; i++){
		if(dist[i] == 0x3f3f3f3f)
			cout<<-1<<endl;
		else
			cout<<dist[i]<<endl;
	}
	return 0;
}
