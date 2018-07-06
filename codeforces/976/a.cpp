#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	cin>>s;
	int n1 = 0;
	int n0 = 0;
	for(int i=0; i<n;i++){
		if(s[i] == '0') n0++;
		else n1++;
	}

	if(n1){
		cout<<1;
		for(int i=0; i<n0;i++) cout<<0;
	}
	else
		cout<<0;

	cout<<endl;

	return 0;
}
