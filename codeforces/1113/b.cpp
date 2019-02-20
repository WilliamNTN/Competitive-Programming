#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 50123;
int n;
int vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	LL total = 0;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		total += vals[i];
	}

	sort(vals,vals+n);
	LL ans = total;
	for(int i = 1; i<n; i++){
		for(int j = 2; j<= vals[i]; j++){
			if(vals[i]%j != 0) continue; 
			int div = vals[i]/j;
			int mult = vals[0]*j;
			int diff = (vals[i]-div) - (mult-vals[0]);
			LL newTotal = total - vals[i] - vals[0] + div + mult;
			ans = min(ans,newTotal);
		}
	}
	cout<<ans<<endl;

	return 0;
}
