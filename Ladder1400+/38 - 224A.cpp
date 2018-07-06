#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL a1,a2,a3;
LL v1,v2,v3;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a1>>a2>>a3;

	v1 = sqrt((a1*a2)/a3);
	v2 = a1/v1;
	v3 = a2/v1;
	cout<<v1*4 + v2*4 + v3*4<<endl;
	return 0;
}
