#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n,m;
int a,b;
vector<int> graph[101234];
int visited[101234];

bool dfs(int a, int b){
	visited[a] = 1;
	if(a == b)
		return true;
	
	for(int i=0; i<graph[a].size(); i++){
		int v = graph[a][i];
		if(visited[v] == 0){
			if(dfs(v,b))
				return true;
		}
	}

	return false;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>a>>b;

	while(m--){
		int c,d;
		cin>>c>>d;
		graph[c].push_back(d);
	}

	if(dfs(a,b))
		cout<<"SIM"<<endl;
	else
		cout<<"NAO"<<endl;

	return 0;
}
