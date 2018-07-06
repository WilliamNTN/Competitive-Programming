#include <bits/stdc++.h>
using namespace std;
#define LL long long int

set<int> present;
int n,a;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		present.insert(a);
	}

	int count = 0;
	for(int i=1;i<=n;i++)
		if(present.count(i) == 0) count++;

	cout<<count<<endl;
	return 0;
}
