#include <bits/stdc++.h>
using namespace std;
#define LL long long int

string a,b;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b;
	if(a.size() != b.size()){
		cout<<"NO"<<endl;
		return 0;
	}
	int ans = 1;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[b.size()-1-i]) ans = 0;
	}

	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
