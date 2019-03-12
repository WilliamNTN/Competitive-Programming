#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;

vector<pii> vec;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	for(int i = 0; i < 5; i++){
		int u,v;
		cin>>u>>v;
		vec.pb(mp(u,v));
	}
	sort(vec.begin(),vec.end());

	int a,b;
	cin>>a>>b;
	int id = lower_bound(vec.begin(),vec.end(),mp(a,b)) - vec.begin();
	cout<<id<<endl;
	return 0;
}
