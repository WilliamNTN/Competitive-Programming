#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,m;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	if(n >= m){

		for(int i = 0; i < m; i++)
			cout<<"BG";

		for(int i = 0; i < (n-m); i++)
			cout<<"B";
		cout<<endl;
	}
	else{
		for(int i = 0; i < m; i++)
			cout<<"GB";

		for(int i = 0; i < (n-m); i++)
			cout<<"G";
		cout<<endl;
	}

	return 0;
}
