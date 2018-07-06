#include <bits/stdc++.h>
using namespace std;


#define LL long long int
#define fi first
#define se second
#define Pair pair<LL,LL>
bool compare(const pair<LL,LL> &a, const pair<LL,LL> &b){
	if(a.fi != b.fi)
		return (a.fi < b.fi);
	return a.se < b.se;
}

Pair events[5012345];
LL eventsP = 0;
LL n,k;
int main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;

	for(LL i = 0; i<n; i++){
		LL a,b;
		cin>>a>>b;
		events[eventsP++] = make_pair(a,-1);
		events[eventsP++] = make_pair(b,1);
	}

	sort(events, events+eventsP, compare);

	Pair results[5012345];
	LL resultsP = 0;

	LL left = 0;
	LL balance = 0, balanceAnt = 0;
	for(LL i = 0; i<eventsP; i++){
		balanceAnt = balance;
		balance -= events[i].se;

		if(balance == k && balanceAnt == (k-1))
			left = events[i].fi;
		else if(balance == (k-1) && balanceAnt == k){
			results[resultsP++] = make_pair(left,events[i].fi);
		}


	}

	cout<<resultsP<<"\n";
	for(LL i=0; i<resultsP; i++)
		cout<<results[i].fi<<" "<<results[i].se<<"\n";

	return 0;
		
}
