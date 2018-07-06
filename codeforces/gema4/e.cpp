#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n,m;



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	LL valores[n+1];

    valores[0]=0;;
	for(int i=1; i<=n; i++){
		cin>>valores[i];
		valores[i] = valores[i] + valores[i-1];
	}

	cin>>m;
	int count = 0;

	while(count < m){
		count++;
		int a,b;
		cin>>a>>b;
		cout<<valores[b] - valores[a-1]<<endl;
	}


	return 0;

}