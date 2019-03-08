#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
vector<pii> edges;
int n,m;
int maxDegree,root;

map<int,int> groupSize;
map<int,int> parent;
map<int,int> degree;

int getParent(int a){

	int v  = a;
	while(parent[v] != v)
		v = parent[v];
	return v;
}
vector<pii> unionFind(int root){
	for(int i = 0; i < n; i++){
		parent[i] = i;
		groupSize[i] = 1;
	}
	parent[root] = root;
	vector<pii> ans;

	for(int i = 0; i < m; i++){
		if(edges[i].ff == root || edges[i].ss == root){
			pii edge = edges[i];
			int u = edge.ff;
			int v = edge.ss;

			int up = getParent(u);
			int vp = getParent(v);

			if(up != vp){
				if(groupSize[up] >= groupSize[vp]){
					parent[vp] = up;
					groupSize[up] += groupSize[v];
				}
				else{
					parent[up] = vp;
					groupSize[vp] += groupSize[up];
				}

				ans.pb(mp(u,v));
			}

			if(groupSize[root] == n) break;
		}
	}
	for(int i = 0; i < m && groupSize[root] < n; i++){
		pii edge = edges[i];
		int u = edge.ff;
		int v = edge.ss;

		int up = getParent(u);
		int vp = getParent(v);

		if(up != vp){
			if(groupSize[up] >= groupSize[vp]){
				parent[vp] = up;
				groupSize[up] += groupSize[v];
			}
			else{
				parent[up] = vp;
				groupSize[vp] += groupSize[up];
			}

			ans.pb(mp(u,v));
		}

		if(groupSize[root] == n) break;
	}

	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b;
		cin>>a>>b;
		edges.pb(mp(a,b));
		degree[a]++;
		degree[b]++;

		if(degree[a] > maxDegree){
			maxDegree = degree[a];
			root = a;
		}
		if(degree[b] > maxDegree){
			maxDegree = degree[b];
			root = b;
		}
	}

	vector<pii> ans =  unionFind(root);

	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
	return 0;
}
