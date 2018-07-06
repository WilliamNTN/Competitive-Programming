#include <bits/stdc++.h>
using namespace std;

#define LL long long int
LL n;
string s;

map<pair<char,char>,LL> occur;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;

	LL greater = 0;
	pair<char,char> p;
	for(int i=0; i<(n-1);i++){
		occur[make_pair(s[i],s[i+1])]++;
		if(occur[make_pair(s[i],s[i+1])] > greater){
			greater = occur[make_pair(s[i],s[i+1])];
			p = make_pair(s[i],s[i+1]);
		}
	}

	cout<<p.first<<p.second<<endl;

	return 0;
}
