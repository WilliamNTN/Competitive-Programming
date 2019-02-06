
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
string s;
string t;

bool isVowel(char c){
	return (c=='a' || c == 'e' || c =='i' || c == 'o' || c == 'u');
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s>>t;
	if(s.size() != t.size()){
		cout<<"No"<<endl; return 0;
	}
	else{
		for(int i = 0; i < s.size(); i++){
			if(isVowel(s[i]) != isVowel(t[i])){
				cout<<"No"<<endl;
				return 0;
			}
		}
	}

	cout<<"Yes"<<endl;
	return 0;
}
