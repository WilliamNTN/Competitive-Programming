#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n;
LL vals[1012];



int solve(LL *vec, LL pos, int *conf){

	if(pos >= n)
		return 1;

	for(LL i=0; i<n; i++){
		if(conf[i] == 0){

			if( (vec[pos-1]*2) == vals[i]){

				conf[i] = 1;
				vec[pos] = vals[i];

				if(solve(vec,pos+1,conf)==1)
					return 1;

				conf[i] = 0;
			}

			else if((vec[pos-1]/3) == vals[i]){

				conf[i] = 1;
				vec[pos] = vals[i];

				if(solve(vec,pos+1,conf)==1)
					return 1;

				conf[i] = 0;
			}
		}
	}

	return 0;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>n;

	for(LL i=0; i<n; i++)
		cin>>vals[i];

	int res = 0;
	LL count = 0;

	LL *aux = (LL*)malloc(sizeof(LL)*1012);

	while(res == 0){
		int *conf = (int*)calloc(1012,sizeof(int));

		aux[0] = vals[count];
		conf[count] = 1;

		res = solve(aux,1,conf);

		count++;
	}

	cout<<aux[0];
	for(LL i=1; i<n; i++)
		cout<<aux[i]<<" ";
	cout<<endl;
	return 0;
}
