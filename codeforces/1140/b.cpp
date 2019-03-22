#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		string s;
		int n;
		cin>>n>>s;
		if(n <= 1 || s[0] == '>' || s[n-1] == '<'){
			cout<<0<<endl;
		}
		else
			cout<<1<<endl;

	}
	return 0;
}