
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL q;
LL l,r,d;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>q;
	while(q--){
		cin>>l>>r>>d;
		if(d < l) cout<<d<<endl;
		else cout<< r + (d-(r%d))<<endl;
	}
	return 0;
}
