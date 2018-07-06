#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	while(n > 0){
		n--;
		string s;
		cin>>s;
		if(s.size() <= 10)
			cout<<s<<endl;
		else{
			cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
		}
	}
	return 0;
}
