#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL n,k;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	LL totalRed = 1ll*2*n;
	LL totalGreen = 1ll*5*n;
	LL totalBlue = 1ll*8*n;

	LL ans = ceil(totalRed/(k*1.0));
	ans += ceil(totalBlue/(k*1.0));
	ans += ceil(totalGreen/(k*1.0));
	cout<<ans<<endl;
	return 0;
}
