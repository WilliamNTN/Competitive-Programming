#include <bits/stdc++.h>
using namespace std;

#define LL long long int


LL n;


bool test(LL m){

	return ((m*(m+1)/2) >= n);
}

LL bs(){
	LL l = 0;
	LL r = 2*n;

	while(l < r){
		LL m = (l+r)/2;

		if(test(m)){
			r = m;
		}
		else
			l = m+1;
	}

	return r;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	
	LL max = bs();
	LL sum = max*(max+1)/2;
	cout<<max-(sum-n)<<endl;
	return 0;
}
