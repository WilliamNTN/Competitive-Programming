#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 550;
int n,m;
int vals[maxN][maxN];
vector<int> uniquesSort[maxN];
vector<int> aux[maxN];

int getIndex(int val, int row){

	for(int i = 0; i < m; i++)
		if(vals[row][i] == val) return i+1;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>vals[i][j];
			aux[i].pb(vals[i][j]);
		}
		sort(aux[i].begin(),aux[i].end());
	}
	
	for(int i = 0; i < n; i++){
		uniquesSort[i].pb(aux[i][0]);
		for(int j = 1; j < m; j++){
			if(aux[i][j] == aux[i][j-1]) continue;
			uniquesSort[i].pb(aux[i][j]);
		}
	}

	
	LL result = uniquesSort[0][0];
	for(int i = 1; i < n; i++){
		result = result ^ uniquesSort[i][0];
	}
	if(result != 0){
		cout<<"TAK"<<endl;
		for(int i = 0; i < n; i++)
			cout<<getIndex(uniquesSort[i][0],i)<<" ";
		cout<<endl;
	}else{
		int t = -1;
		for(int i = 0; i < n; i++){
			if(uniquesSort[i].size() > 1){
				t = i;
				break;
			}
		}

		if(t == -1){
			cout<<"NIE"<<endl;
		}
		else{
			cout<<"TAK"<<endl;
			for(int i = 0; i < n; i++){
				cout<<getIndex(uniquesSort[i][i == t?1:0],i)<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
