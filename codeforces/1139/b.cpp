#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL n;
LL vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(LL i = 0; i < n; i++)
		cin>>vals[i];

	LL ans = vals[n-1];
	LL before = vals[n-1];
	for(LL i = n-2; i >= 0; i--){
		LL thisBuy = min(vals[i],before-1);
		ans += thisBuy;
		before = thisBuy;
		if(thisBuy <= 1) break;
	}
	cout<<ans<<endl;

	return 0;
}
