#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<LL,LL>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const LL maxN = 201234;
vector<LL> indexes[maxN];
vector<pii> fre;

LL vals[maxN];
LL n,m,k;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	k = n/m;

	for(LL i = 0; i<n; i++){
		cin>>vals[i];
		indexes[vals[i]%m].pb(i);
	}

	LL final = 0;

	for(LL i = 0; i < 2*m; i++){
		LL cur = i%m;

		while(indexes[cur].size() > k){
			LL elem = indexes[cur].back();
			indexes[cur].pop_back();
			fre.pb(mp(elem,i));

		}

		while(indexes[cur].size() < k && fre.size()){
			LL elem = fre.back().ff;
			LL mmod = fre.back().ss;
			fre.pop_back();

			indexes[cur].pb(elem);
			vals[elem] += i-mmod;
			final += i-mmod;


		}
	}

	cout<<final<<endl;
	for(LL i = 0; i<n; i++)
		cout<<vals[i]<<" ";
	cout<<endl;
	return 0;
}
