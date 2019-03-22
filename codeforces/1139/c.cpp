#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
vector<LL> graph[maxN];
LL n,k;
int visited[maxN];
LL mod = pow(10,9) + 7;

LL powMod(LL x, LL y){ 
    LL res = 1;     
  
    x = x % mod;    
    while (y > 0){        
        if (y & 1) 
            res = (res*x) % mod;  
        y = y>>1;  
        x = (x*x) % mod;   
    } 
    return res; 
} 

LL bfs(LL start){

	LL ans = 0;
	queue<LL> q;
	q.push(start);
	visited[start] = 1;
	while(q.size()){
		LL u = q.front(); q.pop();
		ans++;
		//cout<<"Get "<<u<<endl;
		for(LL i = 0; i < graph[u].size(); i++){
			LL v = graph[u][i];
			//cout<<"Look "<<v<<endl;
			if(visited[v] == -1){
				visited[v] = 1;
				q.push(v);
				//cout<<"Add "<<v<<endl;
			}
		}
	}

	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(LL i = 0; i < (n-1); i++){
		LL u,v,x;
		cin>>u>>v>>x;
		if(x == 0){
			graph[u].pb(v);			
			graph[v].pb(u);			
		}
	}
	memset(visited,-1,sizeof(visited));
	LL ans = powMod(n,k);
	for(LL i = 1; i <= n; i++){
		if(visited[i] == -1){
			//cout<<"BFS at "<<i<<endl; 
			LL number = bfs(i);
			//cout<<"TOTAl = "<<number<<endl;
			LL thisV = powMod(number,k);
			ans = (((ans - thisV)%mod)+mod)%mod;

		}
	}

	cout<<ans<<endl;
	return 0;
}
