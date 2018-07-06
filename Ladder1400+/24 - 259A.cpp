#include <bits/stdc++.h>
using namespace std;
#define LL long long int

string entry;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int ans = 1;

	for(int i=0; i<8; i++){
		cin>>entry;
		for(int i=1; i<entry.size(); i++)
			if(entry[i] == entry[i-1]) ans = 0;
	}

	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
