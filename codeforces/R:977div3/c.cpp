#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,k;
LL vals[1012345];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>vals[i];

	sort(vals,vals+n);

	
	if(k == 0){
		if(vals[0] > 1)
			cout<<vals[0]-1<<endl;
		else
			cout<<-1<<endl;
	}

	else if(k == n)
		cout<<vals[k-1]<<endl;

	else if(vals[k-1] == vals[k])
		cout<<-1<<endl;

	else
		cout<<vals[k-1]<<endl;

	return 0;
}
