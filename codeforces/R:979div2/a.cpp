#include <bits/stdc++.h>
using namespace std;

#define LL long long int
LL n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n; 

	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	
	n++;
	if(n%2 == 0){
		cout<<n/2<<endl;
	}
	else{
		cout<<n<<endl;
	}
	return 0;
}
