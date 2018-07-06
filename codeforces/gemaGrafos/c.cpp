#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
int n,m,a,b,u,v;

vector<pair<int,int> > edges;

int visited[1010];

bool dfs(int a,vector<int> graph[1010]){
	visited[a] = 1;

	for(int i=0; i<graph[a].size(); i++){
		int v = graph[a][i];
		if(v == b) return true;
		if(visited[v] == 0){
			if(dfs(v,graph))
				return true;
		}
	}

	return false;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>a>>b;

	if(m == 0){
		cout<<"NAO"<<endl;
		return 0;
	}
	
	while(m--){
		cin>>u>>v;
		edges.push_back(make_pair(u,v));
	}

	for(int j=0; j<edges.size(); j++){
		vector<int> graph[1010];
		memset(visited,0,sizeof(visited));

		for(int i=0;i<edges.size(); i++){
			if(i == j) continue;
			graph[edges[i].ff].push_back(edges[i].ss);
			graph[edges[i].ss].push_back(edges[i].ff);
		}
		if(!dfs(a,graph)){
			cout<<"NAO"<<endl;
			return 0;
		}
	}
	cout<<"SIM"<<endl;
	return 0;
}
