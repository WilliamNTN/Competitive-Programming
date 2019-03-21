#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1012345678;
LL n;
LL q;
LL x,y;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>q;
	while(q--){
		cin>>x>>y;
		
		LL valuesBefore = (x-1)*(n/2);
		LL extraEven = 0, extraOdd = 0;
		LL ans = 0;
		if(n%2 != 0){
			extraEven = extraOdd = (x-1)/2;
			if((x+1)%2 != 0) extraEven++;
		}

		extraEven += (y-1)/2;
		extraOdd += (y-1)/2;
		
		if(y%2 == 0){
			if((x+1)%2 == 0) extraEven++;
			else extraOdd++;
		}
		
		if((x+y)%2 == 0){
			ans = valuesBefore + extraEven + 1;
		}	
		else{
			LL start = pow(n,2)/2;
			ans = valuesBefore + extraOdd + start+1+(n%2);
		}
		cout<<ans<<endl;	
	}
	return 0;
}
