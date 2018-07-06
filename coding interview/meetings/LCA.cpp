#include <bits/stdc++.h>
using namespace std;
#define LL long long int


const int maxN = 101010; // > 10^5


vector<int> graph[maxN];
int parent[maxN];

int n,k,a,b;			// nvertices,narestas, no1, no2;

void bfs(int);
int LCA(int,int,int);
int getMin(vector<int>, vector<int>);
int getMinVideo(vector<int>, vector<int>);
int binarySearch(vector<int>, int);

void bfs(int root){
	queue<int> q;

	q.push(root);
	parent[root] = root;

	while(q.size()){
		int v = q.front(); q.pop();
		for(int i=0; i<graph[v].size(); i++){
			int u = graph[v][i];
			
			if(parent[u] == -1){
				parent[u] = v;
				q.push(u);
			}
		}
	}

}

int LCA(int no1, int no2, int root){

	vector<int> pathN1,pathN2;

	int actual = no1;
	pathN1.push_back(actual);
	while(actual != root){
		actual = parent[actual];
		pathN1.push_back(actual);
	}

	actual = no2;
	pathN2.push_back(actual);
	while(actual != root){
		actual = parent[actual];
		pathN2.push_back(actual);
	}

	//sort(pathN1.begin(), pathN1.end());

	return getMinVideo(pathN1,pathN2);
}

int getMin(vector<int> sorted, vector<int> original){

	for(int i = 0; i<original.size(); i++){
		int bs = binarySearch(sorted, original[i]);
		if(bs == original[i])
			return original[i];
	}

	return -1; 
}
int getMinVideo(vector<int> a, vector<int> b){ // começa a percorrer o nosso vetor de trás (o ultimo sempre é a raiz)
											   // vai começar sempre igual, os dois tem a raiz. Quando parar de ser igual
											   // vai ser dali pra frente sempre diferente, então a resposta é o ultimo valor
											   // que foi igual nos dois. Complexidade O(n)
	int ans = -1;
	int pa = a.size()-1, pb = b.size()-1;

	while(pa >= 0 && pb >= 0){
		if(a[pa] == b[pb])
			ans = a[pa];
		else
			break;
		pa--;pb--;
	}

	return ans;
}
int binarySearch(vector<int> vec, int key){

	int l = 0, r = vec.size();

	while( l < r){
		int m = (l+r)/2;
		if(vec[m] >= key){
			r = m;
		}
		else{
			l = m+1;
		}
	}

	return vec[l];

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k>>a>>b;
	for(int i = 0; i<k; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	memset(parent,-1,sizeof(parent));

	bfs(1);

	cout<<LCA(a,b,1)<<endl;
	return 0;
}
