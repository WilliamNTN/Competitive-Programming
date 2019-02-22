#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n;
int vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>vals[i];
	sort(vals,vals+n);

	LL ans = 0;
	for(int i = 0 ; i < n; i+=2){
		ans += vals[i+1] - vals[i];
	}
	cout<<ans<<endl;
	return 0;
}
