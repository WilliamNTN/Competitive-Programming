#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pair pair<int,int>			//problems solved / time penalty

int n,k;
pair teams[50];

bool compare(const pair &a, const pair &b){
	if(a.fi == b.fi)
		return (a.se < b.se);
	return a.fi > b.fi;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		teams[i] = make_pair(a,b);
	}

	sort(teams, teams+n, compare);

	pair ref = teams[k-1];
	int c = 0;
	for(int i=0;i<n;i++)
		if( (teams[i].fi == ref.fi) && (teams[i].se == ref.se) )
			c++;

	cout<<c<<endl;

	return 0;
}
