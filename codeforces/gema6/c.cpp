#include <bits/stdc++.h>
using namespace std;

#define LL long long int
LL n,m;
vector<LL> vals;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(LL i=0;i<n;i++){
		LL a;
		cin>>a;
		vals.push_back(a);
	}

	while(m--){
		LL aux;
		cin>>aux;
		LL posL,posR;
		posL = lower_bound(vals.begin(),vals.end(), aux) - vals.begin();
		posR = upper_bound(vals.begin(),vals.end(), aux) - vals.begin();

		if(vals[posL] == aux){
			cout<<aux<<endl;
		}else{
			if(posL > 0) posL--;
			LL dif1 = abs(aux - vals[posL]);
			LL dif2 = abs(aux - vals[posR]);

			if(dif1 <= dif2)
				cout<<vals[posL]<<endl;
			else
				cout<<vals[posR]<<endl;
		}

	}
	return 0;
}