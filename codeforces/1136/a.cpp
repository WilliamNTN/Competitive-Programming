#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n,k;
int vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <= n; i++){
		int a,b;
		cin>>a>>b;
		vals[i] = b;
	}
	cin>>k;

	int chap = 1;
	for(chap; chap <= n; chap++){
		if(vals[chap] >= k) break;
	}
	int ans = n - chap + 1;
	cout<<ans<<endl;
	return 0;
}
