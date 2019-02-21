#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL n,m,k;
LL vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
	}
	sort(vals,vals+n);
	LL total = 0;
	LL cycle = k+1;
	LL nCycles = m/cycle;
	total += nCycles * (k*vals[n-1]+vals[n-2]);
	m-=cycle*nCycles;
	total += m*vals[n-1];
	cout<<total<<endl;
	return 0;
}
