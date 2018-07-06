#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n,m;
char mat[2020][2020];
map<int,int> unused;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	
	for(int i = 0; i<n;i++){
		int thisUse = 0, couldNotUse = 0;
		for(int j = 0; j<m; j++){
			if(mat[i][j] == '1'){
				thisUse++;
				for(int k= 0; k<n;k++){
					if(k != i){
						if(mat[k][j] == '1'){
							couldNotUse++;
							k = n;
						}

					}
				}
			}
		}
		if(thisUse == couldNotUse)
			unused[i] = 1;
	}

	int ans = 0;
	for(int i = 0; i<n; i++)
		if(unused[i] == 1)
			ans = 1;

	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}
