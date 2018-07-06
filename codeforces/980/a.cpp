#include <bits/stdc++.h>
using namespace std;
#define LL long long int

string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	int p = 0, l = 0;
	for(int i=0; i<s.size(); i++)
		if(s[i] == '-') l++;
		else p++;

	if (p==0 || (l%p) == 0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}
