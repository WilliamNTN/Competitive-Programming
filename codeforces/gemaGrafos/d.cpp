#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
vector<int> graph[101234];
int dist[101234];


void bfs(int a){
	memset(dist,-1,sizeof(dist));

	queue<int> q;

	dist[a] = 0;
	q.push(a);

	while(q.size()){
		int u = q.front(); q.pop();

		for(int i=0; i<graph[u].size(); i++){
			int v = graph[u][i];
			if(dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>a>>b;

	while(m--){
		int c,d;
		cin>>c>>d;

		graph[c].push_back(d);
		graph[d].push_back(c);
	}

	bfs(a,b);
	cout<<dist[b]<<endl;
	
	return 0;
}
