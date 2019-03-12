#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 501234;
int n,m;
vector<pii> passes;
int vals[maxN];
vector<int> toPass;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
		cin>>vals[i];
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		passes.pb(mp(u,v));
	}
	sort(passes.begin(),passes.end());
	toPass.pb(vals[n-1]);
	int ans = 0;
	for(int i = n-2; i>= 0; i--){
		bool flag = true;
		for(int j = 0; j < toPass.size(); j++){
			int id = lower_bound(passes.begin(),passes.end(),mp(vals[i],toPass[j])) - passes.begin();
			if(passes[id].ff != vals[i] || passes[id].ss != toPass[j])
				flag = false;
		}
		if(flag){
			ans++;
		}else{
			toPass.pb(vals[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
