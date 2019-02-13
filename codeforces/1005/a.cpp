
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1010;
int n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	vector<int> ans;
	cin>>n;
	int last = -1;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		if(a == 1 && i != 0)
			ans.pb(last);
		last = a;
	}
	ans.pb(last);
	cout<<ans.size()<<endl;
	for(int i = 0; i <ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
