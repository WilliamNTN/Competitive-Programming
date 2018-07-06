#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>n;

	for(int i=0; i<=n; i++){ // line

		for(int j=0; j<(n-i); j++)
			cout<<"  ";

		cout<<0;

		for(int j=1; j<=i; j++)
			cout<<" "<<j;
		for(int j = (i-1); j>=0; j--)
			cout<<" "<<j;

		cout<<endl;

	}

	for(int i = (n-1); i>=0; i--){
		for(int j=0; j<(n-i); j++)
			cout<<"  ";

		cout<<0;

		for(int j=1; j<=i; j++)
			cout<<" "<<j;
		for(int j = (i-1); j>=0; j--)
			cout<<" "<<j;

		cout<<endl;
	}

	return 0;
}
