#include <bits/stdc++.h>
using namespace std;

#define LL long long int


LL n,m;
LL pieces[51];


void printPieces(){
    for(LL i=0;i<m;i++)
        cout<<pieces[i]<<endl;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(LL i = 0; i<m; i++)
		cin>>pieces[i];

	sort(pieces,pieces+m);
   	
   	int menor = 101234;

   	for(LL i = 0; i<(m-(n-1));i++){
   		if( (pieces[i+(n-1)] - pieces[i]) < menor)
   			menor = ( pieces[i+(n-1)] - pieces[i] );
   	}

   	cout<<menor<<endl;
	return 0;
}
