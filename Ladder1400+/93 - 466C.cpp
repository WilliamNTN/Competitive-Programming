#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 501234;

int n;
int vals[maxN];
set<pii> dp;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	vals[0] = 0;
	for(int i = 1; i<=n; i++){
		cin>>vals[i];
		vals[i] += vals[i-1];
	}
	
	return 0;
}
