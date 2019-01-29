
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
vector<LL> graph[maxN];
vector<pair<LL,LL>> interval;
LL n;



bool bfs(LL src, LL dst){

	if(src == dst) return true;
	vector<bool> visited(maxN,false);
	queue<int> q;
	q.push(src);
	visited[src] = true;

	while(q.size()){
		int u = q.front(); q.pop();

		for(int i = 0; i < interval.size(); i++){
			if(u == i || visited[i]) continue;
			int a = interval[u].ff;
			int b = interval[u].ss;
			int c = interval[i].ff;
			int d = interval[i].ss;

			if((c < a && a < d)||(c < b && b < d)){
				if(dst == i) return true;
				q.push(i);
				visited[i] = true;
			}
		}
	}

	return false;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	while(n--){
		LL cmm,a,b;
		cin>>cmm>>a>>b;

		if(cmm == 1){
			interval.pb(mp(a,b));
		}	
		else{
			if(bfs(a-1,b-1))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}
