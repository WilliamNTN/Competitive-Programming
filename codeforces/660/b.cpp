#include <bits/stdc++.h>
using namespace std;

int n,m;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	int finalPos[4*n];
	memset(finalPos,-1,sizeof(finalPos));

	for(int i=(2*n)+1, j = 0; i<=m; i++, j+=2){
		finalPos[j] = i;
	}

	for(int i=1, j= 1; i<=(2*n) && i <= m; i++, j+=2)
		finalPos[j] = i;

	for(int i=0; i<(4*n); i++){
		if(finalPos[i] != -1)
			cout<<finalPos[i]<<" ";
	}
	cout<<endl;
	return 0;
}
