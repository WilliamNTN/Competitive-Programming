#include <bits/stdc++.h>
using namespace std;


int n,x,y;
vector<int> graph[301234];
int visited[301234];
int dp[301234];


int dfs(int a, int gotX){
	visited[a] = 1;
	int sum = 0;

	for(int i=0; i<graph[a].size(); i++){
		int v = graph[a][i];

		if(visited[v] == 0){

			if(v != x  && v != y){
				sum += dfs(v,gotX)+1;
			}
			else if(v == x){
				sum += dfs(v,1)+1;
			}
			else if( gotX == 0){
				sum += dfs(v,gotX)+1; 
			}
		}
	}

	return sum;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>x>>y;

	for(int i=0;i<(n-1);i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	for(int i=1; i<=n; i++){
		memset(visited,0,sizeof(visited));
		if(i == x)
			dp[i] = dfs(i,1);
		else
			dp[i] = dfs(i,0);
	}

	int total = 0;
	for(int i=1; i<=n; i++)
		total += dp[i];
	cout<<total<<endl;
	return 0;
}
