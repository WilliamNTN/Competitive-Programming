
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
const LL mod = 998244353;
string s;
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	LL pt0 = 1;
	LL pt1 = n-2;

	while(pt0 < n && s[pt0] == s[pt0-1]) pt0++;
	while(pt1 >= pt0 && s[pt1] == s[pt1+1]) pt1--;
	LL l1 = pt0;
	LL l2 = n-pt1-1;
	LL ans = ((l1%mod) + (l2%mod))%mod;
	if(s[pt0-1] == s[pt1+1]) ans += ((l1 * l2)%mod);
	ans = (ans + 1)%mod;
	cout<<ans<<endl;
	return 0;
}
