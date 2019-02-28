#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
int n;
map<int,vector<int>> vals;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <= (2*n); i++){
		int a; cin>>a;
		vals[a].pb(i);
	}

	LL total = 0;
	int last = 1;
	for(int i = 1; i <= n; i++){
		total += abs(last - vals[i][0]);
		last = vals[i][0];
		vals[i].erase(vals[i].begin());
	}
	last  = 1;
	for(int i = 1; i <= n; i++){
		total += abs(last - vals[i][0]);
		last = vals[i][0];
		vals[i].erase(vals[i].begin());
	}
	cout<<total<<endl;
	return 0;
}
