#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int n,v;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>v;
	LL total = min(n-1,v);
	for(int i = 2; i <= n-v; i++)
		total += i;

	cout<<total<<endl;
	return 0;
}
