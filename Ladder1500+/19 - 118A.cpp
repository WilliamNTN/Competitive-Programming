#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){

	return ((c=='a' || c == 'o' || c == 'y' || c=='e' || c == 'u' || c == 'i'));
}

string s;
#define LL long long int
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;

	for(int i=0; i<s.size(); i++){
		s[i] = tolower(s[i]);
		if(!isVowel(s[i])){
			cout<<"."<<s[i];
		}
	}

	cout<<endl;

	return 0;
}
