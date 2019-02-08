
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
LL n,d;
vector<LL> vals;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>d;
	for(int i = 0; i < n; i++){
		LL a; cin>>a;
		vals.pb(a);
	}

	LL ans = 0;
	for(int i = 0; i < n-2; i++){
		LL position = lower_bound(vals.begin(),vals.end(),vals[i]+d) - vals.begin();
		if(position == n || vals[position] > vals[i]+d)  position--;
		LL len = position-i-1;
		ans += len*(len+1)/2;
	}
	cout<<ans<<endl;
	return 0;
}