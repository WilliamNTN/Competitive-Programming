#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
int n;
int colors[maxN];
vector<int> graph[maxN];
pii colorsSubTree[maxN];
int visited[maxN];
int root = 0;

pii getColors(int vertex){
	int red = 0;
	int blue = 0;
	visited[vertex] = 1;
	if(colors[vertex] == 1) red++;
	if(colors[vertex] == 2) blue++;
	for(int i = 0; i < graph[vertex].size(); i++){
		int u = graph[vertex][i];
		if(visited[u] != -1) continue;
		pii r = getColors(u);
		red += r.ff;
		blue += r.ss;
	}
	return colorsSubTree[vertex] = mp(red,blue); 
}

int bfs(){
	memset(visited,-1,sizeof(visited));
	visited[1] = 1;
	queue<int> q;
	q.push(1);
	int ans = 0;
	while(q.size()){
		int v = q.front(); q.pop();
		if(v != 1){
			pii rootColors = colorsSubTree[1];
			pii thisColors = colorsSubTree[v];
			if(thisColors.ff == 0 || thisColors.ss == 0){
				rootColors.ff -= thisColors.ff;
				rootColors.ss -= thisColors.ss;
				if(rootColors.ff == 0 || rootColors.ss == 0)
					ans++;
			}
		}
		for(int i = 0; i < graph[v].size(); i++){
			int u = graph[v][i];
			if(visited[u] == -1){
				visited[u] = 1;
				q.push(u);
			}
		}
	}

	return ans;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <=n; i++)
		cin>>colors[i];
	for(int i = 1; i <= n-1; i++){
		int a,b;
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	memset(visited,-1,sizeof(visited));
	getColors(1);

	LL ans = bfs();
	cout<<ans<<endl;
	return 0;
}
