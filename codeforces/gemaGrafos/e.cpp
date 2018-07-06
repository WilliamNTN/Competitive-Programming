#include <bits/stdc++.h>
using namespace std;

int mat[1010][1010];
vector<int> graph[1010];
int dist[1010];
int n;

void bfs(int a) {
    memset(dist, -1, sizeof dist);
    queue<int> q;

    dist[a] = 0;
    q.push(a);

    while(q.size()) {
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
			if(mat[i][j] == 1)
				graph[i].push_back(j);
		}
	}

	for(int i=0;i<n;i++){
		bfs(i);
		for(int j=0; j<n; j++){
			if(dist[j] != mat[i][j]){
				cout<<"nao"<<endl;
				return 0;
			}
		}
	}
	cout<<"sim"<<endl;
	return 0;
}
