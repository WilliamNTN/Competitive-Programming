#include <bits/stdc++.h>
using namespace std;

int n,m,k;

char matrix[1000][1000];
int results[1000][1000];
bool done[1000][1000];

vector<pair<int,int> > used;



int dfs(int a, int b){
	done[a][b] = true;
	used.push_back(make_pair(a,b));

	int somaP = 0;

	for(int i = -1; i<=1; i+=2){
		if(a+i >=0 && a+i < n){
			if(matrix[a+i][b] == '.'){
				if(!done[a+i][b]){
					somaP += dfs(a+i,b);
				}
			}
			else{
				somaP++;
			}
		}
		if(b+i >=0 && b+i < m){
			if(matrix[a][b+i] == '.'){
				if(!done[a][b+i]){
					somaP += dfs(a,b+i);
				}
			}
			else{
				somaP++;
			}
		}
	}

	return somaP;

}

void solve(int result){

	for(int i=0; i<used.size(); i++){
		results[used[i].first][used[i].second] = result;
	}

	used.clear();
}

int main(){

	cin>>n>>m>>k;

	for(int i=0;i<n;i++)
		for(int j = 0; j<m;j++)
			cin>>matrix[i][j];

	for(int i = 0; i<n; i++)
		for(int j = 0; j<m;j++){
			if(matrix[i][j] == '.' && !done[i][j]){
					solve(dfs(i,j));
			}
		}

	int count = 0;

	while(count < k){
		count++;
		int a,b;
		cin>>a>>b;
		a--;b--;
		cout<<results[a][b]<<endl;
	}

	return 0;
}