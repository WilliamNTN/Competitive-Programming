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
vector<LL> vals;
map<LL,LL> hashMap;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		LL a; cin>>a;
		vals.pb(a);
	}

	sort(vals.begin(),vals.end());
	int ans = 0;

	for(int i = 0; i < n; i++){
		int thisSkill = vals[i];
		int limitSkil = thisSkill + 5;
		int position = upper_bound(vals.begin(),vals.end(),limitSkil) - vals.begin();
		int thisRange = position - i;
		ans = max(ans,thisRange);
	}
	cout<<ans<<endl;


	return 0;
}
