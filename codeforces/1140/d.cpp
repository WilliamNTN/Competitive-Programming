#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	LL ans = 0;
	for(int i = 2; i < n; i++)
		ans += i * (i+1);
	cout<<ans<<endl;
	return 0;
}
