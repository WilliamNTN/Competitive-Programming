#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n;
LL vals[301234];

LL getDist(){
	LL target[n];
	for(LL i=1; i<=n; i++)
		target[i-1] = i;

	sort(vals,vals+n);

	LL sum = 0;
	for(LL i=0; i<n; i++)
		sum += abs(vals[i] - target[i]);

	return sum;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>vals[i];

	cout<<getDist()<<endl;

	return 0;
}
