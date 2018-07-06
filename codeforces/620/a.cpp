#include <bits/stdc++.h>
using namespace std;
#define LL long long int 

LL x1,y1,x2,y2;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>x1>>y1>>x2>>y2;

	LL dif1 = abs(x1-x2);
	LL dif2 = abs(y1-y2);

	if(dif1 > dif2)
		cout<<dif1<<endl;
	else
		cout<<dif2<<endl;

	return 0;
}
