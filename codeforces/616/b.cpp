#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n,m;
LL prices[101][101];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>prices[i][j];

	LL menorRua[n];

	for(int i=0;i<n;i++){
		LL menor=prices[i][0];
		for(int j=1; j<m; j++){
			if(prices[i][j] < menor)
				menor = prices[i][j];
		}
		menorRua[i] = menor;
	}

	LL maior = menorRua[0];
	
	for(int i=1;i<n;i++)
		if(menorRua[i] > maior)
			maior = menorRua[i];

	cout<<maior<<endl;
	return 0;
}
