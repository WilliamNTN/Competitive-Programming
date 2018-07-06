#include <bits/stdc++.h>
using namespace std;

long long mat[112][112];


bool menor(long long a, long long b){
	return a < b;
}

bool maior(long long a,long long b){
	return a > b;
}

bool equal(long long a, long long b){
	return a == b;
}

char getPadrao(int fil,int n){
	bool (*func)(long long,long long );

	long long aux = mat[0][fil] - mat[1][fil];

	if(aux > 0)
		func = &maior;
	else if(aux < 0)
		func = &menor;
	else 
		func = &equal;

	for(int i=1;i<(n-1);i++){
		if(!func(mat[i][fil],mat[i+1][fil]))
			return 'N';
	}

	return 'S';
}


int main(){
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>mat[i][j];

		}

	for(int i=0;i<m;i++)
		cout<<getPadrao(i,n)<<endl;

	return 0;
}