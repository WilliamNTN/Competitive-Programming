#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n,a,b,k;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>a>>b>>k;
	LL res = 0;
	for(int i = 0; i<k;i++){
		char c;
		cin>>c;
		if(c == '+'){
			res += pow(a,n-i)*pow(b,i);
		}
		else
			res -= factor*pow(b,i);
	}


	return 0;
}
