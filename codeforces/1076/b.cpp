#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	if(n%2 == 0){
		cout<<n/2<<endl;
	}else{
		for(LL i = 3; (i*i) <= n; i++){
			if(n%i == 0){
				n -= i; break;
			}
		}
		if(n%2 != 0) cout<<1<<endl;
		else cout<<n/2 + 1<<endl;
	}
	return 0;
}
