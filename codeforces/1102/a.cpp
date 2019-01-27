
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 2012345678;
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	long long int sum = (n * (n+1))/2;

	if(sum % 2 == 0) cout<<0<<endl;
	else cout<<1<<endl;

	return 0;
}
