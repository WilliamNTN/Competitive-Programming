#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
int n;
vector<pii> a,b;
vector<pair<pii,int>> entry;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int x,y;
	for(int i = 0; i < n; i++){
		cin>>x>>y;
		entry.pb(mp(mp(x,y),i));
		a.pb(mp(x,i));
		b.pb(mp(y,i));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());



	LL index = b[0].ss;
	LL diff = b[1].ff - (a[n-1].ss == index? a[n-2].ff:a[n-1].ff);
	LL ans = max(1ll*0,diff);
	index = a[n-1].ss;
	diff = (b[0].ss == index? b[1].ff : b[0].ff) - a[n-2].ff;
	ans = max(ans,diff);
	cout<<ans<<endl;
	
	// for(int i = 0; i < n; i++){
	// 	int maxA = a[n-1].ss == i? a[n-2].ff : a[n-1].ff;
	// 	int minB = b[0].ss == i? b[1].ff : b[0].ff;
	// 	int len = minB - maxA;
	// 	ans = max(ans,len);
	// }
	// cout<<ans<<endl;
	

	return 0;
}