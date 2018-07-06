#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n,k;
char mat[4][260];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;

	if(k > (n-2)*4 || ( k>(n-2)*2 && k%2 != 0  )  ){
		cout<<"NO"<<endl;
		return 0;
	}

	for(int j = 1; j<= n-2; j++){
		if(k>0){
			mat[1][j] = '#';
			k--;
		} else break;
		if(k>0){
			mat[2][j] = '#';
			k--;
		}else break;

	}

	for(int j = 1; j<=n-2; j++){
		if(k>0){
			mat[0][j] = mat[3][j] = '#';
			k-=2;
		}
	}

	cout<<"YES"<<endl;
	for(int i = 0; i<4; i++){
		for(int j = 0; j<n; j++)
			cout<<mat[i][j];
		cout<<endl;
	}
	
	

}
