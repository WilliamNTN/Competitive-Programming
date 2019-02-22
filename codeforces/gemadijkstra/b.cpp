#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
vector<pair<int,int> > graph[100012];		// index -> order	
vector<int> cost[100012];					// cost
int dist[100012];							// dijkstra dist
int pr[100012];								// impressao final
int used[100012];							// 
int c,u,v,w;
stack<int> bq;
priority_queue<pair<int,int> > pq;






void dijkstra(int s){
	
	memset(dist,0x3f3f3f3f,sizeof(dist));
	pq.push(make_pair(0,s));
	dist[s] = 0;
	while(pq.size()){
		int u = pq.top().second;
		pq.pop();

		if(used[u]) continue;

		used[u] = 1;
		
		for(int i=0; i<graph[u].size(); i++){

			int v = graph[u][i].first;
			int w = cost[u][i];

			if(dist[v] >= dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(-dist[v],v));		
			}
		}
		
	}
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>a>>b;
	
	c = 0;
	while(c < m){
		
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(v,c));
		graph[v].push_back(make_pair(u,c));

		cost[u].push_back(w);
		cost[v].push_back(w);
		c++;
		pr[c] = 0;						// vetor para print no final
	}
	
	dijkstra(a);						


	// partindo de B, se a distância de um nó V
	// é igual a distância de um nó U, somado com o peso de U->V
	// o nó U faz parte do caminho mínimo
	memset(used,0,sizeof(used));
	bq.push(b);
	while(bq.size()){
		int u = bq.top(); bq.pop();
		if(!used[u]){
			used[u] = 1;
			for(int i=0; i<graph[u].size(); i++){
				int v = graph[u][i].first;
				int w = cost[u][i];
				if(dist[u] == dist[v] + w){
					bq.push(v);
					pr[graph[u][i].second] = 1; // neste caso, a aresta entre U e V deve ser printada no final
				}		
			}
		}
	}

	for(int i=0; i<c;i++){
		if(pr[i] == 1)
			cout<<"sim"<<endl;
		else
			cout<<"nao"<<endl;
	}

	return 0;
}