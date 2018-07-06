#include <bits/stdc++.h>
using namespace std;

int n;
int mn,sum;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	mn = 0;
	sum = 0;

	for(int i=0;i<n;i++){
		int ai;
		cin>>ai;
		sum+=ai;
		if(sum < mn) mn = sum;
	}

	cout<<abs(mn)<<endl;
	return 0;
}
