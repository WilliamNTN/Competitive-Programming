#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n;
int vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
	}
	sort(vals,vals+n);
	vector<int> diffs;
	diffs.pb(vals[0]);
	for(int i = 1; i < n; i++){
		if(vals[i] == vals[i-1]) continue;
		diffs.pb(vals[i]);
	}

	if(diffs.size() > 3){
		cout<<-1<<endl;
		return 0;
	}
	if(diffs.size() == 1){
		cout<<0<<endl;
		return 0;
	}
	if(diffs.size() == 2){
		int a = diffs[1] - diffs[0];
		if(a%2 == 0) cout<<a/2<<endl;
		else cout<<a<<endl;
		return 0;
	}
	int a,b,c;
	a = diffs[0];
	b = diffs[1];
	c = diffs[2];
	if((b-a) == (c-b)){
		cout<<b-a<<endl;
	}
	else
		cout<<-1<<endl;

	return 0;
}
