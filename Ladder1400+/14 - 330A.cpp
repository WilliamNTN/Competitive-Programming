#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int r,c;
char mat[11][11];

map<int,int> row;
map<int,int> col;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>r>>c;

	int nrow = r;
	int ncol = c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c; j++){
			cin>>mat[i][j];
			if(mat[i][j] == 'S'){
				if(!row[i]){
					nrow--;
					row[i] = 1;
				}
				if(!col[j]){
					ncol--;
					col[j] = 1;
				}
			}
		}
	}

	int resCol = (ncol * r);
	int resRow = (nrow * c) - (ncol*nrow);
	
	cout<<resRow + resCol<<endl;
	return 0;
}
