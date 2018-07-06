#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n,m;
LL a,b;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	a = max(n,m);
	b = (n+m)-a;

	LL p2 = a-b;
	 
	return 0;
}
