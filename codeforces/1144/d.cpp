#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL n;
LL vals[maxN];
map<LL,LL> hashMap;
LL greater;
vector<pair<LL,pair<LL,LL>>> ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <=n; i++){
		cin>>vals[i];
	}

	LL greater = vals[0];
	hashMap[vals[1]] = 1;
	for(int i = 2; i <=n; i++){
		hashMap[vals[i]]++;
		if(hashMap[vals[i]] > hashMap[greater])
			greater = vals[i];
	}

	int limit = 1;
	for(int i = 1; i <=n; i++){
		if(vals[i] != greater) continue;

		int v = i;
		while(v > 1 && vals[v] == greater){
			if(vals[v-1] != greater){
				if(vals[v-1] > greater)
					ans.pb(mp(2,mp(v-1,v)));
				else
					ans.pb(mp(1,mp(v-1,v)));
				vals[v-1] = greater;
			}
			v--;
		}

		v = i;
		while(v < n && vals[v] == greater){
			if(vals[v+1] != greater){
				if(vals[v+1] > greater)
					ans.pb(mp(2,mp(v+1,v)));
				else
					ans.pb(mp(1,mp(v+1,v)));
				vals[v+1] = greater;
			}
			v++;
		}
		break;
	}


	cout<<ans.size()<<endl;
	for(int i = 0; i < ans.size();i++)
		cout<<ans[i].ff<<" "<<ans[i].ss.ff<<" "<<ans[i].ss.ss<<endl;

	return 0;
}
