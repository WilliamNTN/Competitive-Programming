#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 0;

int n,m;


int dfs(vector<vector<int> > grid, int x, int y){

	cout<<"St: "<<x<<" "<<y<<endl;
	int a[3] = {-1,0,1};
	int b[3] = {-1,0,1};

	grid[x][y] = -1;
	int count = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int p1 = x + a[i];
			int p2 = y + b[i];

			if(!(p1 >= 0 && p2 >= 0 && p1 < n && p2 < m)) continue;
			if(p1 == x && p2 == y) continue;
			if(grid[p1][p2] != 1) continue;

			grid[p1][p2] = -1;
			count++;
		}
	}

	return count;
}
int solve(vector<vector<int> > grid){

	int n = grid.size();
	int m = grid[0].size();

	int ans = 0;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(grid[i][j] == 1){
				cout<<"GO"<<endl;
				ans = max(ans,dfs(grid,i,j)+1);
			}
		}
	}

	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	vector<vector<int> > t;

	for(int i = 0; i < n; i ++){
		vector<int> aux;
		for(int j = 0; j<m; j++){
			int a; cin>>a;
			aux.pb(a);
		}
		t.pb(aux);
	}


	cout<<solve(t)<<endl;
	return 0;
}
