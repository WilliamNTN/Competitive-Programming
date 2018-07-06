#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	if(n < 0){
		LL aux1 = ((n/100)*10) + n%10;
		n = max(n/10, aux1);
	}
	cout<<n<<endl;

	return 0;
}
