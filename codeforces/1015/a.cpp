#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n,m;
int vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	memset(vals,0,sizeof(vals));
	cin>>n>>m;
	int l,r;
	for(int i = 0; i < n; i++){
		cin>>l>>r;
		for(int j = l; j <= r; j++)
			vals[j] = 1;
	}

	int count = 0;
	for(int i = 1; i <= m; i++){
		if(vals[i] == 0) count++;
	}
	cout<<count<<endl;
	for(int i = 1 ; i  <= m; i++){
		if(vals[i] == 0)
			cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
