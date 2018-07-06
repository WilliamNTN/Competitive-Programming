#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n;
string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	char last = s[0];
	int count = 0;

	for(int i=1; i<s.size(); i++){
		if(s[i] == last)
			count++;
		else
			last = s[i];
	}

	cout<<count<<endl;
	return 0;
}
