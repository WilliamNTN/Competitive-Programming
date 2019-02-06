
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 102134;
const int maxM = 10123456;

LL n,k,m;
LL vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k>>m;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	sort(vals,vals+n);

	int maxToDelete = min(m,n-1);
	m -= maxToDelete;
	for(int i = maxToDelete; i < n; i++){
		if(m == 0) break;
		int maxToAdd = min(k,m);
		vals[i] += maxToAdd;
		m -= maxToAdd;
	}

	double total = 0;
	for(int i = maxToDelete; i< n; i++){
		total += vals[i];
	}

	cout<<fixed<<setprecision(20)<<total/(1.0* (n-maxToDelete))<<endl;
	return 0;
}
