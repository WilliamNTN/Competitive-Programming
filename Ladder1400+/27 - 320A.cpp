#include <bits/stdc++.h>
using namespace std;
#define LL long long int




string n;

bool solve(int pos){
	if(pos >= n.size()) return true;

	if(n[pos] == '1'){
		if(solve(pos+1)) return true;
		if(n[pos+1] == '4')
			if(solve(pos+2)) return true;
		if(n[pos+1] == '4' && n[pos+2] == '4')
			if(solve(pos+3)) return true;
	}

	return false;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	if(solve(0)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;


	return 0;
}
