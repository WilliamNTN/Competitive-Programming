#include <bits/stdc++.h>
using namespace std;

#define LL long long int




LL bPower = 0;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	LL n;
	cin>>n;

	LL vals[n];
	char teams[n];

	for(LL i = 0; i<n; i++)
		cin>>vals[i];

	int left = 0, right = 0;
	LL lSum = 0, rSum = 0;
	LL bSum = 0;
	for(LL i = 0; i<n; i++){
		cin>>teams[i];
		if(teams[i] == 'A'){
			if(!left)
				lSum += vals[i];
			rSum += vals[i];
		}
		if(teams[i] == 'B'){
			left = 1;
			rSum = 0;
			bPower += vals[i];
		}

	}

	bPower += lSum > rSum?lSum:rSum;

	cout<<bPower<<endl;
	return 0;
}
