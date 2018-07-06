#include <bits/stdc++.h>
using namespace std;

string a,b,c;
int ca[26],cc[26];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b>>c;

	for(int i=0; i<a.size(); i++){
		ca[a[i] - 'A']++;
	}
	for(int i=0; i<b.size(); i++){
		ca[b[i] - 'A']++;
	}

	for(int i = 0; i < c.size(); i++)
		cc[c[i] - 'A']++;

	for(int i=0; i<26; i++)
		if(ca[i] != cc[i]){
			cout<<"NO"<<endl;
			return 0;
		}

	cout<<"YES"<<endl;

	return 0;
}
