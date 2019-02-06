
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int t;
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans;
		if(n%2 == 0) ans = n/2;
		else{
			ans = 1;
			n-=3;
			ans += n/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
