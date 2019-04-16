#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
LL n,m;
LL a,b;
vector<LL> diffs;
LL sumA,sumB;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	sumA = sumB = 0;
	for(LL i = 0; i < n; i++){
		cin>>a>>b;
		sumA += a;
		sumB += b;
		diffs.pb(a-b);
	}

	sort(diffs.begin(),diffs.end());
	LL sumDiffs = 0;
	LL ans = 0;
	LL pt = n-1;
	while(pt >= 0 && (sumA - sumDiffs) > m){
		sumDiffs += diffs[pt];
		pt--;
		ans++;
	}
	if((sumA - sumDiffs) > m){
		cout<<-1<<endl;
	}else
		cout<<ans<<endl;
	return 0;
}
