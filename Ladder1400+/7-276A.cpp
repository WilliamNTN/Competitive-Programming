#include <bits/stdc++.h>
using namespace std;

//time 3:36
#define LL long long int
int n,k;

int joy[10123];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>k;

	int maxJoy = -0x3f3f3f3f;
	for(int i=0;i<n;i++){
		int fi,ti;
		cin>>fi>>ti;
		if(ti > k){
			joy[i] = fi - (ti - k);
		}
		else joy[i] = fi;

		maxJoy = max(maxJoy,joy[i]);
	}

	cout<<maxJoy<<endl;

	return 0;
}
