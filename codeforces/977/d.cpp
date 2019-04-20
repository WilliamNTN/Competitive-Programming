#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n;
LL vals[1012];


bool solve(LL *vec, LL vecPos, LL* conf){

	if(vecPos >= n)
		return true;
	
	for(LL i=0; i<n; i++){
		if(conf[i] == 0){

			if((LL)(vec[vecPos-1]*(LL)(2)) == vals[i]){

				vec[vecPos] = vals[i];
				conf[i] = 1;

				if(solve(vec,vecPos+1,conf))
					return true;
				conf[i] = 0;
			}
			else if((LL)( (vec[vecPos-1] % 3 == 0) && (vec[vecPos-1]/(LL)(3)) == vals[i])){

				vec[vecPos] = vals[i];
				conf[i] = 1;

				if(solve(vec,vecPos+1,conf))
					return true;
				conf[i] = 0;
			}
		}
	}

	return false;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	for(LL i=0; i<n; i++){
		cin>>vals[i];
	}


	bool res = false;
	LL count = 0;

	LL* aux = (LL*)malloc(sizeof(LL)*n);

	while(!res){
		LL *conf = (LL*) calloc(n,sizeof(LL));

		aux[0] = vals[count];
		conf[count] = 1;

		res = solve(aux,1,conf);

		count++;
	}	

	cout<<aux[0];
	for(LL i=1;i<n;i++)
		cout<<" "<<aux[i];
	cout<<endl;
	
	return 0;
}
