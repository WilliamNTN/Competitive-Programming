#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 55;
int r1,c1,r2,c2;
int n;
char vals[maxN][maxN];
int visited[maxN][maxN];

void dfs(int x, int y, vector<pii>& all){
	all.pb(mp(x,y));
	visited[x][y] = 1;

	for(int i = -1; i <= 1; i+=2){
		int nx = x;
		int ny = y+i;

		if(nx > 0 && nx <=n && ny > 0 && ny <=n && !visited[nx][ny] && vals[nx][ny] == '0'){
			dfs(nx,ny,all);
		}

		nx = x+i;
		ny = y;

		if(nx > 0 && nx <=n && ny > 0 && ny <=n && !visited[nx][ny] && vals[nx][ny] == '0'){
			dfs(nx,ny,all);
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	cin>>r1>>c1>>r2>>c2;
	for(int i = 1; i <=n; i++)
		for(int j = 1; j <=n; j++)
			cin>>vals[i][j];

	vector<pii> first,second;
	memset(visited,0,sizeof(visited));
	dfs(r1,c1,first);
	memset(visited,0,sizeof(visited));
	dfs(r2,c2,second);

	
	LL minCost = LONG_MAX;
	for(int i = 0; i < first.size(); i++){
		for(int j = 0; j < second.size(); j++){
			LL thisCost = pow((first[i].ff-second[j].ff),2);
			thisCost += pow((first[i].ss - second[j].ss),2);
			minCost = min(minCost,thisCost);
		}
	}
	cout<<minCost<<endl;

	return 0;
}
