#include <bits/stdc++.h>
using namespace std;

#define LL long long int


LL n,m;
LL vals[301234];
LL dists[301234];
map<int,int> pos;

LL min(LL a, LL b){
	return a < b? a: b;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(LL i=0; i<n; i++){
		cin>>vals[i];
		pos[vals[i]] = i;
	}

	memset(dists,0x3f3f3f3f,sizeof(dists));

	while(m--){
		LL c,d;
		cin>>c>>d;
		LL c1 = pos[c];
		LL d1 = pos[d];
		LL diff = abs(c1 - d1);
		if(c1 > d1)
			dists[c1] = diff;
		else
			dists[d1] = diff;
	}

	LL sum = 0, a = 0;	// a = número de segmentos possíveis com a posição 
						// com final no i atual
	for(LL i=1; i<n; i++){
		a = min(a+(LL)1,dists[i]-(LL)1);
		sum+=a;
	}

	cout<<sum+n<<endl; // +n para todo segmento (i,i)

	return 0;
}
