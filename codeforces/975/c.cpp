#include <bits/stdc++.h>
using namespace std;
#define LL long long int
const int NN = 200200;

LL n,q;
LL arrows[NN],accArrows[NN];
LL soldiers[NN], accSoldiers[NN];


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>q;
	for(int i = 0; i<n; i++)
		cin>>soldiers[i];

	for(int i = 0; i<q; i++)
		cin>>arrows[i];

	accSoldiers[0] = soldiers[0];
	for(int i = 1; i<n; i++)
		accSoldiers[i] =accSoldiers[i-1] + soldiers[i];

	LL accArrows = 0;
	for(int i = 0; i<q; i++){
		accArrows += arrows[i];

		LL l = 0, r = n-1;
		LL ans = -1;

		while(l <= r){
			LL m = (l+r)/2;
			if(accSoldiers[m] <= accArrows){
				ans = m;
				l = m+1;
			}
			else	
				r = m-1;
		}
		if(ans == n-1){
			cout<<n<<endl;
			accArrows = 0;
		}
		else
			cout<<(n - (ans+1))<<endl;
		
	}

	return 0;
}
