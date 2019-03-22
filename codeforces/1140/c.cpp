#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define pll pair<long long int, long long int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
LL n,k;
pll bt[maxN];
pll ln[maxN];
map<pii,LL> hashMap;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i = 0; i < n; i++){
		LL a,b;
		cin>>a>>b;
		ln[i] = mp(a,b);
		bt[i] = mp(b,a);
		hashMap[ln[i]]++;
	}
	sort(ln,ln+n);
	sort(bt,bt+n);

	LL ans = bt[n-1].ff * bt[n-1].ss;
	hashMap[mp(bt[n-1].ss,bt[n-1].ff)]--;
	k--;
	LL index = n-2;
	LL thisLen = bt[n-1].ss;
	LL minB = bt[n-1].ff;

	while(k && index >= 0){
		pii actual = ln[index--];
		if(hashMap[actual] == 0) continue;

		LL thisMinB = minB;
		if(actual.ss < thisMinB) thisMinB = actual.ss;
		if((thisLen + actual.ff)*thisMinB > ans){
			ans = (thisLen + actual.ff) * thisMinB;
			thisLen += actual.ff;
			minB = thisMinB;
			k--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
