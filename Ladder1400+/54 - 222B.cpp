#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second

const int maxN = 1010;

int mat[maxN][maxN];
int n,m,k;
map<int,int> cols;
map<int,int> rows;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>k;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin>>mat[i][j];
			cols[j] = j;
			rows[i] = i;
		}
	}

	while(k--){
		char c; int x,y;
		cin>>c>>x>>y;

		if(c == 'g'){

			cout<<mat[rows[x]][rows[y]]<<endl;
		}
		else if(c == 'c'){
			int aux = cols[x];
			cols[x] = cols[y];
			cols[y] = aux;
		}
		else if(c == 'r'){
			int aux = rows[x];
			rows[x] = rows[y];
			rows[y] = aux;
		}
	}


	return 0;
}
