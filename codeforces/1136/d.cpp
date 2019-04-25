#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 501234;
int n,m,ans;

vector<int> graph[maxN];

int vals[maxN];
map<int,int> isInP;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		vals[i]--;
	}
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		graph[u].pb(v);
	}
	ans = 0;
	isInP[vals[n-1]] = 1;
	int count = 1;
	for(int i = n-2; i >= 0; i--){
		int thisCount = 0;
		for(int j = 0; j < graph[vals[i]].size(); j++){
			if(isInP[graph[vals[i]][j]]) thisCount++;
		}
		if(thisCount == count) ans++;
		else{
			isInP[vals[i]] = 1;
			count++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
