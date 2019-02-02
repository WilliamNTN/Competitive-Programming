
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1012345678;
LL a,b,k;
int t;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		cin>>a>>b>>k;
		LL right = ceil(k/2.0);
		LL left = k/2.0;
		cout<<a*right-left*b<<endl;
	}
	return 0;
}
