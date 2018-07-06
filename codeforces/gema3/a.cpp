#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,m,a;
	cin>>n>>m;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>a;
			if(a==0){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}

	return 0;
}