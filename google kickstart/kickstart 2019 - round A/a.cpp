#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int p;
int n;
int vals[maxN];
int t;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int count = 1; count <= t; count++){
		int n,p;
		cin>>n>>p;
		for(int i = 0; i < n; i++)
			cin>>vals[i];
		sort(vals,vals+n);

		int ans = 0x3f3f3f3f;
		int sum = 0;
		for(int i = 0; i < p; i++)
			sum += vals[i];
		int total = vals[p-1]*p;
		int diff = total-sum;
		ans = min(ans,diff);
		for(int i = p; i < n; i++){
			sum -= vals[i-p];
			sum += vals[i];
			int total = vals[i]*p;
			int diff = total-sum;
			ans = min(ans,diff);
		}

		cout<<"Case #"<<count<<": "<<ans<<endl;
	}
	return 0;
}
