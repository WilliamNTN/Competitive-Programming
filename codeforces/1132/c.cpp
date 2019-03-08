#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 5050;
int n,q;
pii p[maxN];
int paint[maxN];
int cumSum[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>q;
	for(int i = 1; i <= q; i++){
		int l,r;
		cin>>l>>r;
		p[i] = mp(l,r);
	}
	int ans = 0;
	for(int x = 1; x <= q; x++){
		memset(paint,0,sizeof(paint));
		memset(cumSum,0,sizeof(cumSum));
		for(int i = 1; i <= q; i++){
			if( i == x) continue;
			paint[p[i].ff] += 1;
			paint[p[i].ss + 1] -= 1;
		}
		int total = 0;
		for(int j = 1; j <= n; j++){
			paint[j] += paint[j-1];
			if(paint[j] > 0) total++;
		}
		for(int j = 1; j <= n; j++)
			if(paint[j] == 1) cumSum[j] = 1;

		for(int j = 1; j<= n; j++)
			cumSum[j] += cumSum[j-1];

		for(int j = 1; j <= q; j++){
			if(j == x) continue;
			int thisTotal = cumSum[p[j].ss] - cumSum[p[j].ff - 1];
			ans = max(ans,total-thisTotal);
		}
	}
	cout<<ans<<endl;


	return 0;
}
