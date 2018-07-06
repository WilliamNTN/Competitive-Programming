#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL a,b;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b;
		if(b*log(a) > a * log(b))
			cout<<">"<<endl;
		else if(b*log(a) < a*log(b))
			cout<<"<"<<endl;
		else cout<<"="<<endl;

	return 0;
}
