#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define pair pair<LL,LL>
#define fi first
#define se second


LL n;
pair laps[101234];

bool comparePrice(const pair &a, const pair &b){
	return a.fi <= b.fi;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(LL i=0;i<n;i++){
		LL a,b;
		cin>>a>>b;
		laps[i] = make_pair(a,b);
	}

	sort(laps,laps+n,comparePrice);

	for(LL i =0;i<(n-1);i++){
		if( (laps[i].fi < laps[i+1].fi) && (laps[i].se > laps[i+1].se)){
			cout<<"Happy Alex"<<endl;
			return 0;
		}
	}

	cout<<"Poor Alex"<<endl;
	return 0;
}
