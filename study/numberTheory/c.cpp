#include <bits/stdc++.h>
using namespace std;
#define LL long long int


LL n,m;


LL solve(int g, int l){

	LL sum = 0;
	int i;
	for(int i = 0; pow(2,i+1)-1 <= l; i++);

	for(i; pow(2,i+1)-1 <= g; i++){
		sum += i;
	}

	return sum;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	if(n > m) cout<<solve(n,m)<<endl;
	if(m > n) cout<<solve(m,n)<<endl;
	cout<<0<<endl;
	return 0;
}
