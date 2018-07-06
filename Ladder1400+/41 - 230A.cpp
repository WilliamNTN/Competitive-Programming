#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define ff first
#define ss second

LL s,n;
vector<pair<int,int> > dragons;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		dragons.push_back(make_pair(a,b));
	}

	sort(dragons.begin(),dragons.end());

	int ans = 1;
	for(int i=0; i<dragons.size(); i++){
		if(s <= dragons[i].ff){
			ans = 0; break;
		}
		s += dragons[i].ss;
	}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
