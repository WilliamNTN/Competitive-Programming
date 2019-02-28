#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define pll pair<long long int, long long int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 10010;
LL n;
pll vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <=n; i++){
		LL a,b;
		cin>>a>>b;
		vals[i] = mp(a,b);
	}
	vals[0] = mp(0,0);
	LL ans = 0;
	for(int i = 1; i <=n; i++){
		LL a = vals[i].ff;
		LL b = vals[i].ss;

		LL aa =vals[i-1].ff;
		LL bb = vals[i-1].ss;
		
		ans += max(1ll*0,(min(a,b) - max(aa,bb))+1);
		if(a == aa && b == bb) ans--;
		cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
