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
map<char,int> hashMap;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	for(int i = 0; i < s.size(); i++){
		hashMap[s[i]]++;
	}

	int ans = hashMap['a'] + (hashMap['a']-1);
	ans = min(ans,(int)s.size());
	cout<<ans<<endl;
	return 0;
}
