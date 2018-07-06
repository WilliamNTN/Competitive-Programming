#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,m;
LL tasks[101234];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	tasks[0] = 0;
	for(LL i =1; i<=m; i++)
		cin>>tasks[i], tasks[i]--;

	LL totalDist = 0;
	for(LL i = 0; i<(m); i++){
		LL dist = (tasks[i+1] - tasks[i]) % n;
		if(dist < 0)
			dist += n;
		totalDist += dist;
	}

	cout<<totalDist<<endl;

	return 0;
}
