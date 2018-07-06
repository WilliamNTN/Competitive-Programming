#include <bits/stdc++.h>
using namespace std;

int n,x,y;
vector<int> graph[301234];
int visited[301234];

void dfs(int a){
	visited[a] = 1;
	

	for(int i=0; i<graph[a].size(); i++){
		int v = graph[a][i];

		if(!visited[v] && v != y){
			dfs(v);
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>x>>y;

	for(int i=0; i<n-1; i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	
	memset(visited,0,sizeof(visited));
	dfs(x);

	int totalExpected = (n*(n-1));
	int totalExpectedForX = n-1;
	int totalReachedByX = 0;
	for(int i=1; i<=n; i++)
		if(visited[i]) totalReachedByX++;

	int deficit = totalReachedByX * (totalReachedByX - (totalReachedByX-1));
	cout<<totalExpected - deficit<<endl;
	return 0;
}
	