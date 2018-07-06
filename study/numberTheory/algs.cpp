#include <bits/stdc++.h>
using namespace std;
#define LL long long int


//gcd(a,b) == gcd(b,a%b)
LL gcd(int a, int b){ //O(log a*b)
	if(a%b == 0) return b;

	return gcd(b,a%b);
}

// gcd(a,b) * lcm(a,b) = a*b;
// lcm(a,b) == a*b/gcd(a,b);
LL lcm(int a, int b){	// O(log a*b);
	return ((a*b)/(gcd(a,b)));
}


//dont even ask
bool isPrime(LL x){		// O(sqrt(N))
	if (x <= 1)  return false;
	if (x <= 3)  return true;

	if (x%2 == 0 || x%3 == 0) return false;

	for (LL i=5; i*i<=x; i=i+6)
	    if (x%i == 0 || x%(i+2) == 0)
	       return false;

	return true;
}

//get all primes from in [2,n]
vector<LL> getAllPrimes(LL n){ // O(n log log n)

	vector<LL> primes;
	LL arr[n+1];
	memset(arr,-1,sizeof(arr));

	for(LL i = 2; i<=n; i++){
		if(arr[i] == -1){
			primes.push_back(i);
			for(LL j = 2*i; j <= n; j +=i)
				arr[j] = 0;
		}
	}

	return primes;
}


/////////////////////
int buildTree(int node, int start, int end){
	if(start == end)
		return tree[node] = vals[start];

	int mid = (start+end)/2;

	return tree[node] = buildTree(2*node, start, mid) + buildTree(2*node + 1, mid+1, end);

}

int getSum(int node, int start, int end, int l, int r){
	if(r < start || l > end) return 0;

	if(l <= start && r >= end)
		return tree[node];

	int mid = (start+end)/2;
	return getSum(2*node,start, mid, l, r) + getSum(2*node + 1, mid+1,end,l,r);
}

void update(int node, int start, int end, int index, int change){

	if(start == end){
		tree[node] += change;
		return;
	}

	int mid = (start + end)/2;

	if(start <= index && index <= mid)
		 update(2*node,start, mid, index, change);
	else
		update(2*node+1,mid+1,end,index,change);

	tree[node] = tree[2*node] + tree[2*node+1];
	return ;

}
/////////////////////////

void dijkstra(int s){
	
	memset(dist,0x3f3f3f3f,sizeof(dist));

	pq.push(make_pair(0,s));
	dist[s] = 0;
	while(pq.size()){
		int u = pq.top().second;
		pq.pop();

		if(used[u]) continue;

		used[u] = 1;
		//cout<<"dijkstra "<<u<<endl;
		for(int i=0; i<graph[u].size(); i++){

			int v = graph[u][i].first;
			int w = cost[u][i];

			if(dist[v] >= dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(-dist[v],v));		
			}
		}
		
	}
}
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
void bfs(int a){
	memset(dist,-1,sizeof(dist));

	queue<int> q;

	dist[a] = 0;
	q.push(a);

	while(q.size()){
		int u = q.front(); q.pop();

		for(int i=0; i<graph[u].size(); i++){
			int v = graph[u][i];
			if(dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
////////////////////////////////////

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	return 0;
}
