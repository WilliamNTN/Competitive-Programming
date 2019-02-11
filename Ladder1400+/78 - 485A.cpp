
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int a,m;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>m;
	set<int> seen;
	
	while(a%m != 0){
		if(seen.find(a%m) != seen.end()) break;
		seen.insert(a%m);
		a += (a%m);
	}	
	if(a%m == 0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
