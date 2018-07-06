#include <bits/stdc++.h>
using namespace std;

int n,m;
char mat[101][101];


vector<pair<int,int> > getN(int a, int b){

	vector<pair<int,int> > res;
	
	for(int i=(a-1); i <= (a + 1); i++){
		for(int j = (b-1); j <= (b+1); j++){
			if(i != a || j != b){
				if(i >= 0 && j >= 0 && i < n && j < m){
					res.push_back(make_pair(i,j));
				}
			}
		}
	}


	return res;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	for(int i=0; i<n; i++)
		for(int j=0; j<m;j++)
			cin>>mat[i][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<m;j++){

			if(mat[i][j] == '.'){
				vector<pair<int,int> > nei;
				nei = getN(i,j);
				int nbombs = 0;
				for(int k = 0; k<nei.size(); k++){
					if(mat[nei[k].first][nei[k].second] == '*')
						nbombs++;
				}
				if(nbombs != 0){
					cout<<"NO"<<endl; return 0;
				}
					
			}

			else if(mat[i][j] != '*'){
				int val = mat[i][j] - '0';
				vector<pair<int,int> > nei;
				nei = getN(i,j);
				int nbombs = 0;

				for(int k = 0; k<nei.size(); k++){
					if(mat[nei[k].first][nei[k].second] == '*')
						nbombs++;
				}
				if(nbombs != val){
					cout<<"NO"<<endl; return 0;
				}
			}

		}
	}
	
	
	cout<<"YES"<<endl;
	return 0;
}
