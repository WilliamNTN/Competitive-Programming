#include <bits/stdc++.h>
using namespace std;
#define LL long long int
const int maxN = 201234;

LL n;
LL vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i<n; i++) cin>>vals[i];

	sort(vals,vals+n);
	
	LL diff = vals[n-1] - vals[0];

	cout<<diff<<" ";

	LL c1 = 1, c2 = 1;
	LL l1 = 1, l2 = n-2;

	while(vals[l1] == vals[0] && l1 < n-1){
		l1++; c1++;
	}
	
	while(vals[l2] == vals[n-1] && l2 >= l1){
		l2--;c2++;
	}

	if(diff == 0)
		cout<<c1*(c1+1)/2<<endl;
	else
		cout<<c1*c2<<endl;

	return 0;
}
