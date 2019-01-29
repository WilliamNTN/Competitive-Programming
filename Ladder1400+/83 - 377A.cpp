
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 550;

char maze[maxN][maxN];
int visited[maxN][maxN];

int n,m,k,nk;


void dfs(int i, int j){
	if(nk == 0) return;
	nk--;
	visited[i][j] = 1;
	if(nk == 0) return;

	for(int a = -1; a <= 1; a++){
		for(int b = -1; b <= 1; b++){
			if(a != 0 && b != 0) continue;
			if(a == 0 && b == 0) continue;
			int ni = i+a;
			int nj = j+b;
			if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
			if(maze[ni][nj] != '.') continue;
			if(visited[ni][nj]) continue;
			dfs(ni,nj);
			if(nk == 0) return;
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	memset(visited,0,sizeof(visited));
	cin>>n>>m>>k;
	nk = 0;
	int fi = -1, fj = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>maze[i][j];
			if(maze[i][j] == '.') nk++;
			if(maze[i][j] == '.' && fi == -1){
				fi = i; fj = j;
			}
		}
	}

	nk = nk - k;
	dfs(fi,fj);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(maze[i][j] == '.' && visited[i][j] == 0)
				cout<<'X';
			else
				cout<<maze[i][j];
		}
		cout<<endl;
	}
	return 0;
}
