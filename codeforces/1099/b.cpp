
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;

LL n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int upperLimit = ceil(sqrt(n));

	int complete = n/upperLimit;
	int ans = upperLimit + complete;
	if(n%upperLimit != 0) ans++;

	cout<<ans<<endl;
	return 0;
}


