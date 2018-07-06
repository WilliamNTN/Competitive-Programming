#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define mp make_pair

set<pair<char,char> > pairs;
string s;
void setSP(){

	pairs.insert(mp('b','d'));
	pairs.insert(mp('o','o'));
	pairs.insert(mp('p','q'));
	pairs.insert(mp('v','v'));
	pairs.insert(mp('w','w'));
	pairs.insert(mp('x','x'));
	pairs.insert(mp('A','A'));
	pairs.insert(mp('H','H'));
	pairs.insert(mp('I','I'));
	pairs.insert(mp('M','M'));
	pairs.insert(mp('O','O'));
	pairs.insert(mp('T','T'));
	pairs.insert(mp('U','U'));
	pairs.insert(mp('V','V'));
	pairs.insert(mp('W','W'));
	pairs.insert(mp('X','X'));
	pairs.insert(mp('Y','Y'));

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;

	int ans = 1;

	setSP();
	for(int i=0; i<s.size()/2; i++){
		pair<char,char> a = mp(s[i],s[s.size()-i-1]);
		pair<char,char> b = mp(s[s.size()-i-1],s[i]);

		if(pairs.count(a) == 0 && pairs.count(b) == 0){
			ans = 0;
		}
		
	}

	if(s.size() % 2 != 0){
		pair<char,char> a = mp(s[s.size()/2 ],s[s.size()/2 ]);
		if(pairs.count(a) == 0){
			ans = 0;
		}
	}

	if(ans)
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;

	return 0;
}
