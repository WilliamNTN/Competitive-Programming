#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define LL long long int

LL n;
LL last;
LL vals[2123];

LL gcd(LL u, LL v){
	while(v != 0){
		LL r = u % v;
		u = v;
		v = r;
	}

	return u;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	LL last,aux;

	cin>>last;
	vals[0] = last;
	LL count = 0;
	for(int i=1; i<n; i++){
		cin>>aux;

		if(gcd(aux,last) != 1){

			vals[i+count] = 1;
			count++;
			vals[i+count] = aux;
		}
		else{
			vals[i+count] = aux;
			
		}
		last = vals[i+count];
	}


	cout<<count<<endl;
	for(int i=0; i<(n + count); i++)
		cout<<vals[i]<<" ";
	cout<<endl;
	return 0;
}
