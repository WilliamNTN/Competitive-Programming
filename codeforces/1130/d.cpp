#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 20020;
int n,m;
map<int,vector<int>> stations;

int dist(int a,int b){
	if(b >= a)
		return b-a;
	return n-a+b;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b;
		cin>>a>>b;
		stations[a].pb(b);
	}
	int bestDists[maxN];
	for(int i = 1; i<=n; i++){
		if(stations[i].size() == 0) continue;
		int bestDist = INT_MAX;
		for(int j = 0; j < stations[i].size(); j++){
			bestDist = min(bestDist,dist(i,stations[i][j]));
		}
		bestDists[i] = bestDist;
	}
	
	for(int start = 1; start <= n; start++){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(stations[i].size() == 0) continue;
			int thisDist = dist(start,i) + n*(stations[i].size()-1) + bestDists[i];
			ans = max(ans,thisDist);
		}
		cout<<ans<<" ";
	}
	cout<<endl;
	

	return 0;
}
