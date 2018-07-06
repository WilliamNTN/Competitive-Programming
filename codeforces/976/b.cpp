#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,m,k;
LL ci,cj;

//moveID 0 = move ci n-1 down;
//moveId 1 = move cj m-1 right;

//moveId 2 = move cj m-2 left
//moveId 3 = move cj m-2 right 


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>k;
	int ci = 1,cj = 1;
	if(k <= (n-1)+(m-1)){
		if(k <= (n-1)){
			ci += k;
			cout<<ci<<" "<<cj<<endl;
			return 0;
		}
		ci = n;
		k -= (n-1);
		cj += k;
		cout<<ci<<" "<<cj<<endl; return 0;
	}
	int iUp = 0;
	int fromLeft = 1;
	k-=( (n-1) + (m-1));
	while(k > 0){
		k-=(m-1);
		iUp++;
		fromLeft = fromLeft? 0:1;
	}
	if(fromLeft) cj = m-abs(k);
	else cj = 2 + abs(k);
	ci = n - iUp;

	cout<<ci<<" "<<cj<<endl;
	return 0;
}
