#include <bits/stdc++.h>
using namespace std;
#define LL long long int


string entry;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>entry;

	for(int i=0; i<entry.size(); i++){
		if(entry[i] == 'Q' || entry[i] == 'H' || entry[i] == '9'){
			cout<<"YES"<<endl;
			return 0;
		}
	}

	cout<<"NO"<<endl;
	return 0;
}
