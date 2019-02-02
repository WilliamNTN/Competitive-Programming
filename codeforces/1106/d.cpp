
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
LL n,m;

vector<LL> graph[maxN];
int visited[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i = 0; i < m; i++){
		LL a,b;
		cin>>a>>b;
		a--;
		b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	vector<LL> ans;
	priority_queue<LL,vector<LL>, greater<LL> > pq;
	pq.push(0);
	set<LL> used;
	used.insert(0);
	while(pq.size()){
		LL currNode = pq.top(); pq.pop();
		ans.pb(currNode);
		for(int i = 0; i < graph[currNode].size(); i++){
			LL u = graph[currNode][i];
			if(used.find(u)  == used.end()){
				used.insert(u);
				pq.push(u);
			}

		}
	}

	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i]+1<<" ";
	cout<<endl;
	return 0;	
}
