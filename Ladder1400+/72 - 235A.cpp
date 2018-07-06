#include <bits/stdc++.h>
using namespace std;

#define LL long long int



int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	LL ans;
	if(n <= 3){
		if(n == 1) ans = 1;
		if(n == 2) ans = 2;
		if(n == 3) ans = 6;
	}
	else{
		if(n%2 !+ 0)
			ans = n*(n-1)*(n-2);
		else{
			ans = 0
			for(LL i = (n >= 51)? n-50 : 1; i <= n; i+=3)
				ans = max(ans,i*(i+1)*(i+2));
		}
	}

	cout<<ans<<endl;
	return 0;
}
