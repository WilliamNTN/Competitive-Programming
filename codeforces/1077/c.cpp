
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 202134;




vector<pii> vec;
LL sum;
int n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	sum = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		sum += a;
		vec.pb(mp(a,i+1));
	}

	sort(vec.begin(),vec.end());
	
	vector<int> ans;
	for(int i = 0; i < n-1; i++){
		if(sum - vec[i].ff - vec[n-1].ff == vec[n-1].ff){
			ans.pb(vec[i].ss);
		}
	}

	if(sum - vec[n-1].ff-vec[n-2].ff == vec[n-2].ff)
		ans.pb(vec[n-1].ss);

	cout<<ans.size()<<endl;
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
