#include <bits/stdc++.h>
using namespace std;
#define LL long long int

// Returns largest power of p that divides n!
LL largestPower(LL n, LL p){
    // Initialize result
    LL x = 0;
 
    // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n){
        n /= p;
        x += n;
    }
    return x;
}

LL n,p;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>p;
	cout<<largestPower(n,p);

	return 0;
}
