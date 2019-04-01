#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int q;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>q;
	while(q--){
		LL l,r;
		cin>>l>>r;
		LL firstEven = (l%2 == 0)?l:(l+1);
		LL lastEven = (r%2==0)?r:(r-1);

		LL nEvenTotal = lastEven/2;
		LL nEvenBefore = max(1ll*0,firstEven-2)/2;


		LL sumEven = nEvenTotal*(nEvenTotal+1) - nEvenBefore*(nEvenBefore+1);


		LL firstOdd = (l%2 != 0)?l:(l+1);
		LL lastOdd = (r%2 != 0)?r:(r-1);

		LL nOddTotal = ceil(lastOdd/2.0);
		LL nOddBefore = ceil(max(1ll*0,firstOdd-2)/2.0);


		LL sumOdd = pow(nOddTotal,2) - pow(nOddBefore,2);
		cout<<sumEven - sumOdd<<endl;
	}
	return 0;
}
