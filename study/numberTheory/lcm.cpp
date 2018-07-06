#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n;


LL lcm(LL a, LL b){
	return (a * b) / __gcd(a,b);
}

LL solve(LL n){

	if(n == 1) return 1;
	if(n == 2) return 2;
	if(n == 3) return 6;

	return lcm(n,lcm(n-1,n-2));
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	cout<<solve(n)<<endl;

	return 0;
}
