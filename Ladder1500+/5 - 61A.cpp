#include <bits/stdc++.h>
using namespace std;

string a,b;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b;
    string c (a.size(),'0');
	for(int i=0;i<a.size();i++){
		c[i] = ((a[i] - '0') ^ (b[i] - '0')) + '0';
	}

	cout<<c.substr(0,a.size())<<endl;
	return 0;
}
