#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n;
string s;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;

	int ans = 1;

	if(n == 1 && s[0] != '1') ans = 0;

	if(s[0] == '0' && s[1] == '0') ans = 0;
	if(s[n-2] == '0' && s[n-1] == '0') ans = 0;
	if( (s[0] == '1' && s[1] == '1') || (s[n-2] == '1' && s[n-1] == 1) ) ans = 0;
	for(int i=1; i<(n-1); i++){
		if(s[i] == '0' && s[i-1] == '0' && s[i+1] == '0')
			ans = 0;
		if(s[i] == '1'){
			if(s[i-1] == '1' || s[i+1] == '1')
				ans = 0;
		}
	}

	if(ans) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
