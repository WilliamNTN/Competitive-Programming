#include <bits/stdc++.h>
using namespace std;

int n,x,y;

vector<int> graph[301234];
int dp[301234];

int dfs(int a, int alreadyx){
	int visited[n];
	memset(visited,0,sizeof(visited));
	visited[a] = 1;
	int sum = 0;
	if(a == x)
		alreadyx = 1;

	for(int i=0; i<graph[a].size(); i++){
		int v = graph[a][i];
		if(v != x && v != y && visited[v] == 0)
			sum += dfs(v,alreadyx)+1;

		else{
			if(v == x && visited[v] == 0){
				
					sum += dfs(v,1)+1;
			
			}
			if(v == y){
				if(alreadyx == 0 && visited[v] == 0){
						sum += dfs(v,alreadyx)+1;
					
				}
			}
		}
	}
	cout<<"Em "<<a<<"foi "<<sum<<endl;
	dp[a] = sum;
	return dp[a];
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>x>>y;

	for(int i=0; i<(n-1);i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1,0);
	int sum = 0;
	for(int i=1; i<=n;i++)
		sum += dp[i];

	cout<<sum<<endl;
	return 0;
}
