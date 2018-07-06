#include <bits/stdc++.h>
using namespace std;


int n;
int vals[1123];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>vals[i];

	sort(vals,vals+n);

	for(int i=2; i<n; i+=2)
		if(vals[i] > vals[i-1])
			swap(vals[i],vals[i-1]);

	for(int i=0; i<n; i++)
		cout<<vals[i]<<" ";

	cout<<endl;
	return 0;
}
