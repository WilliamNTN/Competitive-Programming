#include <bits/stdc++.h>
using namespace std;


#define LL long long int

LL n,m;
char matrix[1001][1001];
LL results[1001][1001];
LL done[1001][1001];

void printMatrix(){

	for(LL i=0;i<n;i++){
		for(LL j=0;j<n;j++)
			cout<<matrix[i][j];
		cout<<endl;
	}
}

LL dfs(LL a, LL b){
	done[a][b] = 1;
	LL ret = 1;


	for(LL i = -1; i<=1; i+=2){
		if(((a+i)>=0) && ((a+i)<=(n-1))){
			if( (matrix[a+i][b] == '.') && (!done[a+i][b]))
				ret += dfs(a+i,b);
		}
	}

	for(LL i = -1; i<=1; i+=2){
		if(((b+i)>=0) && ((b+i)<=(m-1))){
			if( (matrix[a][b+i] == '.') && (!done[a][b+i]))
				ret += dfs(a,b+i);
		}
	}

	return ret;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	

	for(LL i=0;i<n;i++){
		string aux;
		cin>>aux;
		for(LL j=0;j<m;j++)
			matrix[i][j] = aux[j];
	}
	
	for(LL i=0;i<n;i++){
		for(LL j=0;j<m;j++){
			if(matrix[i][j] == '*'){
				results[i][j] = dfs(i,j);
				memset(done,0,sizeof(done));
			}
				
		}
	}

	for(LL i=0;i<n;i++){
		for(LL j=0;j<m;j++)
			if(results[i][j] == 0)
				cout<<'.';
			else
				cout<<results[i][j]%10;

		cout<<endl;
	}




	
	return 0;
}