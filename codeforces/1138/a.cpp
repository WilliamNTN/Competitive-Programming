#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int n;
int vals[maxN];
vector<pii> ans;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	int count = 1;
	for(int i = 1; i < n; i++){
		if(vals[i] == vals[i-1])
			count++;
		else{
			ans.pb(mp(vals[i-1],count));
			count = 1;
		}
	}

	ans.pb(mp(vals[n-1],count));
	int maxAns = 0;
	for(int i = 0; i < ans.size()-1; i++){
		if(ans[i].ff != ans[i+1].ff){
			maxAns = max(maxAns,min(ans[i].ss,ans[i+1].ss)*2);
		}
	}
	cout<<maxAns<<endl;
	return 0;
}
