#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 2020;
int n;
int vals[maxN];
vector<pair<int,pii>> ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <=n; i++)
		cin>>vals[i];

	int target = n-1;
	int sum = 0;
	for(int i = n; i >= 1; i--){
		int thisMod = (vals[i]+sum)%n;
		int op;
		if(thisMod <= target){
			op  = target-thisMod;
		}else{
			op = (n-thisMod)+target;
		}
		ans.pb(mp(1,mp(i,op)));
		sum += op;
		target--;
	}
	ans.pb(mp(2,mp(n,n)));
	cout<<ans.size()<<endl;
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i].ff<<" "<<ans[i].ss.ff<<" "<<ans[i].ss.ss<<endl;
	return 0;
}
