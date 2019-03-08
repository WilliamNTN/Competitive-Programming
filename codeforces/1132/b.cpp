#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
int n,m;
int vals[maxN];
int t[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	LL totalSum = 0;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		totalSum += vals[i];
	}

	sort(vals,vals+n);
	cin>>m;
	for(int i = 0; i < m; i++){
		cin>>t[i];
	}
	for(int i = 0; i < m; i++){
		cout<<totalSum - vals[n-t[i]]<<endl;
	}
	return 0;
}
