#include <bits/stdc++.h>
using namespace std;

#define LL long long int

string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	int count = 0;
	string hello = "hello";

	for(int i=0; i<s.size(); i++){
		if(s[i]==hello[count])
			count++;
	}

	if(count >= 5)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}
