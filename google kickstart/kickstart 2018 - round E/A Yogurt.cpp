
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second

const int maxN = 5050;
LL t,n,k;
LL vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int count = 1;
	cin>>t;
	while(t--){
		cin>>n>>k;
		memset(vals,0,sizeof(vals));

		for(int i = 0; i < n; i++) cin>>vals[i];

		sort(vals,vals+n);

		int ans = 0;
		int day = 0;
		int lastPos = 0;
		while(day < n){
			int initialPos = upper_bound(vals+lastPos,vals+n,day) - vals;
			int finalPos = min(initialPos + k-1,n-1);

			while(vals[finalPos] <= day && finalPos >= initialPos) finalPos--;

			if(finalPos < initialPos){
				break;
			}
			ans += finalPos - initialPos + 1;
			day++;
			lastPos = finalPos+1;
		}
		cout<<"Case #"<<count++<<": "<<ans<<endl;
	}
	return 0;
}
