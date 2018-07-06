#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n, a,b;
LL total = 0;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	LL maior = 0;

	while(n > 0){
		n--;
		cin>>a>>b;
		total -=a; total += b;
		if(total > maior)
			maior  = total;
	}

	cout<<maior<<endl;

	return 0;
}
