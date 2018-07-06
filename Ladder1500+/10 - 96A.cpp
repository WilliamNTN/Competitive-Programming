#include <bits/stdc++.h>
using namespace std;

#define LL long long int

string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;

	int count = 1;
	for(int i=1; i<s.size();i++){

		if(s[i] == s[i-1]){
			count++;
			if(count == 7){
				cout<<"YES"<<endl;
				return 0;
			}
		}
		else
			count = 1;
	}
	cout<<"NO"<<endl;
	return 0;

}
