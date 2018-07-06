#include <bits/stdc++.h>
using namespace std;
#define LL long long int

bool isPrime(LL x){		// O(sqrt(N))
	if (x <= 1)  return false;
	if (x <= 3)  return true;

	if (x%2 == 0 || x%3 == 0) return false;

	for (LL i=5; i*i<=x; i=i+6)
	    if (x%i == 0 || x%(i+2) == 0)
	       return false;

	return true;
}

LL n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	cout<<isPrime(n)<<endl;

	return 0;
}
