#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n,m,k;
int power[maxN];
int sc[maxN];
int sl[maxN];
map<int,priority_queue<pii>> hashMap;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>k;
	for(int i = 1; i <= n; i++)
		cin>>power[i];
	for(int i = 1; i <= n; i++){
		cin>>sc[i];
		hashMap[sc[i]].push(mp(power[i],i));
	}

	for(int i = 1; i <= k; i++)
		cin>>sl[i];

	int ans = 0;
	for(int i = 1; i <=k; i++){
		int id = sl[i];
		int school = sc[id];
		if(hashMap[school].top().ss != id) ans++;
	}
	cout<<ans<<endl;



	return 0;
}
