#include <bits/stdc++.h>
using namespace std;

#define pb push_back
int n;

vector<int> g[101234];	// O(A*V)


void bfs(int s, int *dists){ 

	queue<int> q;	// O(N)
	dists[s] = 0;
	q.push(s);

	while(q.size()){
		int v = q.front(); q.pop();

		for(int i=0; i<g[v].size(); i++){ 	// percorre todos ligados a V
			int u = g[v][i];				// pega um vizinho

			if(dists[u] == 0){	// se ainda não foi visitado
								// atualiza dists e insere para visita
				dists[u] = dists[v] + 1;
				q.push(u);
				if(u == (n-1))
					return;
			}								
		}
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int *dists = (int*)calloc(n,sizeof(int)); // O(N)

	for(int i=0; i<(n-1); i++){
		int a;
		cin>>a;
		for(int j = i+1; j<=(i+a); j++)
			g[i].pb(j);
	}


	bfs(0,dists);
	cout<<dists[--n]<<endl;
	return 0;
}
