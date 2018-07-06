#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 5050;


vector<int> graph[maxN];
int n,m,s;
int visited[maxN];
vector<pii> reach;

bool sortR(const pii a, const pii b){
    return a.ff >= b.ff;
}


int bfs(int a) {
	int dist[maxN];

    memset(dist, -1, sizeof dist);
    queue<int> q;

    dist[a] = 0;
    q.push(a);
    int count = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            if(dist[v] == -1 && visited[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            	count++;
            }
        }
    }

    return count;
}

bool dfs(int a){
	visited[a] = 1;
	
	for(int i=0; i<graph[a].size(); i++){
		int v = graph[a][i];
		if(visited[v] == -1){
			dfs(v);
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>s;
	
    for(int  i = 0; i<m; i++){
        int u,v; cin>>u>>v;
        graph[u].pb(v);
    }

    memset(visited,-1,sizeof(visited));
    dfs(s);

    for(int i = 1; i<=n; i++){
        if(visited[i] == -1){
            int count = bfs(i);
            reach.pb(mp(count,i));
        }
    }

    sort(reach.begin(),reach.end(),sortR);

    int final = 0;
    for(int i = 0; i<reach.size(); i++){
        if(visited[reach[i].ss] == -1){
            final++;
            dfs(reach[i].ss);
        }
    }

    cout<<final<<endl;
	return 0;
}
