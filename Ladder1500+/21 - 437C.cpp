#include <bits/stdc++.h>
using namespace std;

#define LL long long int

#define Pair pair<LL,LL> // index, cost
#define fi first
#define se second


LL n,m;
Pair ener[1012]; 			// fi = index, se = cost
Pair order[1012];			// fi = index, se = cost
int removed[1012];			// 0 = notRemoved, 1 = removed
int conect[1012][1012];		// 0 = notConnected, 1 = connected

bool orderByCostGreater(const Pair &a, const Pair &b){
	return a.se > b.se;
}


LL removeCost(LL index){
	LL cost = 0;
	for(LL i=0; i<n; i++){
		if(conect[index][i] && !removed[i]){
			cost+= ener[i].se; 
		}
	}

	return cost;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	for(LL i =0; i<n; i++){
		LL c;
		cin>>c;
		ener[i] = make_pair(i,c);
		order[i] = ener[i];
	}

	sort(order,order+n,orderByCostGreater); // order to remove

	for(LL i = 0; i<m; i++){
		LL a,b;
		cin>>a>>b;  a--; b--;
		conect[a][b] = conect[b][a] = 1;
	}

	LL totalEnergy = 0;

	for(LL i = 0; i<n; i++){
		LL cost = removeCost(order[i].fi);
		totalEnergy += cost;
		removed[order[i].fi] = 1;
	}

	cout<<totalEnergy<<endl;
	return 0;
}
