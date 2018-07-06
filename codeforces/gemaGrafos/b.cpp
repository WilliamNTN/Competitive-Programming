#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> graph[101234];
int visited[101234];

#define LL long long int

void dfs(int a){
	visited[a] = 1;

	for(int i=0; i<graph[a].size(); i++){
		int v = graph[a][i];
		if(!visited[v])
			dfs(v);
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	while(m--){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int count = 0;

	for(int i=1; i<=n; i++){
		if(visited[i] == 0){
			count++;
			dfs(i);
		}
	}

	cout<<count<<endl;
	return 0;
}
