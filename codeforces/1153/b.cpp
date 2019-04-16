#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 100;
int n,m,h;

int col[maxN];
int row[maxN];
int top[maxN][maxN];
int ans[maxN][maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>h;

	for(int i = 0; i < m; i++)
		cin>>col[i];
	for(int i = 0; i < n; i++)
		cin>>row[i];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>top[i][j];
		}
	}
	memset(ans,0,sizeof(ans));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(top[i][j] != 0){
				ans[i][j] = min(row[i],col[j]);
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
