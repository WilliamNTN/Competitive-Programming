#include <bits/stdc++.h>
using namespace std;

vector<int> graph[201234];
int dist[201234],n,m,x1,x2;
int cc;


vector<int> bfs(int a){
	queue<int> q;
	vector<int> used;
	dist[a] =  1;
	q.push(a);
	used.push_back(a);

	while(q.size()){
		int u = q.front(); q.pop();

		for(int i=0;i<graph[u].size(); i++){
			int v = graph[u][i];
			if(dist[v] == -1){
				dist[v] = 1;
				q.push(v);
				used.push_back(v);
			}
		}
	}

	return used;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x1>>x2;
		graph[x1].push_back(x2);
		graph[x2].push_back(x1);
	}
	memset(dist,-1,sizeof(dist));

	cc = 0;
	for(int i=1; i<=n; i++){
		if(dist[i] == -1){
			vector<int> used = bfs(i);
			int ans = 1;
			for(int j = 0; j<used.size(); j++){
				if(graph[used[j]].size() != 2)
					ans = 0;
			}

			if(ans) cc++;
		}
	}

	cout<<cc<<endl;

	return 0;
}
