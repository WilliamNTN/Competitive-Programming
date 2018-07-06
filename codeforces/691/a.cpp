#include <bits/stdc++.h>
using namespace std;

int n;
set<int> occ;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int a;
	int sum = 0;
	for(int i=0; i<n;i++){
		cin>>a;
		sum +=a;
	}

	if(n == 1){
		if(sum) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else{
		if(sum == n-1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
