#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL r,g,b;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>r>>g>>b;

	LL ans1 = r/3 + g/3 + b/3;
	LL ans2 = 0;
	if(r > 0 && g > 0 && b > 0)
		ans2 = (r-1)/3 + (g-1)/3 + (b-1)/3 + 1;

	LL ans3 = 0;
	if(r > 1 && g > 1 && b > 1)
		ans3 = (r-2)/3 + (g-2)/3 + (b-2)/3 + 2;
	cout<<max(max((LL)0,ans1),max(ans2,ans3))<<endl;
	return 0;
}
