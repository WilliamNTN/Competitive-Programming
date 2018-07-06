#include <bits/stdc++.h>
using namespace std;

//time 12:03 (poor)

int n,t;
string s;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>t;
	cin>>s;

	for(int i=0; i<t; i++){
		for(int j = 0; j<n-1; j++){
			if(s[j] == 'B' && s[j+1] == 'G'){
				swap(s[j],s[j+1]);
				j++;
			}
		}
	}

	cout<<s<<endl;

	return 0;
}
