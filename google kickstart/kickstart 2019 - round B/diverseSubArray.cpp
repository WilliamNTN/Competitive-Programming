#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int n,s,ans,t;
int vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		cin>>n>>s;
		ans = -1;
		for(int i = 0; i < n; i++){
			cin>>vals[i];
		}
		
		cout<<"Case #"<<casen<<": "<<ans<<endl;
	}
	return 0;
}
