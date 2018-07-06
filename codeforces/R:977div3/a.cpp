#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,k;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;

	while(k--){
		if(n%10 != 0)
			n--;
		else
			n = n/10;
	}

	cout<<n<<endl;

	return 0;
}
