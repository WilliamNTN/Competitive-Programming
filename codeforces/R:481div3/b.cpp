#include <bits/stdc++.h>
using namespace std;


int n;
string s;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	cin>>s;

	int count = 0;
	int changes = 0;
	for(int i=0; i<n; i++){
		if(s[i] == 'x'){
			count++;
			if(count == 3){
				changes++;
				count = 2;
			}
		}
		else{
			count = 0;
		}
	}


	cout<<changes<<endl;
	return 0;
}
