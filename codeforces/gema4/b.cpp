#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
char mat[1012][1012];
int done[1012][1012] = {{0}};


int firstTest(){
	
	for(int i=0; i<m;i++){
		if(mat[0][i] == 'U')
			return 1;
		else if(mat[n-1][i] == 'D')
			return 1;
		else if(mat[i][0] == 'L')
			return 1;
		else if(mat[i][m-1] == 'R')
			return 1;
	}

	return 0;
}

string solve(){

	if(!firstTest())
		return "EOQ";
	int count = 0;

	
	while(count <= (n*m)){
	
		if(a < 0 || a >= n || b < 0 || b >= m){
			return "AE MLK";
		}
		
		if(done[a][b]){
			return "EOQ";
		}

		done[a][b] = 1;
		if(mat[a][b] == 'U'){
			a--;
		}
		else if(mat[a][b] == 'D')
			a++;
		else if(mat[a][b] == 'L')
			b--;
		else if(mat[a][b] == 'R')
			b++;

		count++;
	}
	return "EOQ";
}

int main(){

	cin>>n>>m;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
 
	cin>>a>>b;

	cout<<solve()<<endl;

	return 0;
}