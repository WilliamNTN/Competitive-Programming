#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second

const int maxN = 0;

string s;
map<char,int> occ;
set<char> pres;
vector<char> unq;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	int diff = 0;
	for(int i = 0; i<s.size(); i++){
		occ[s[i]]++;
		if(pres.count(s[i]) == 0)
			unq.push_back(s[i]);
		pres.insert(s[i]);	
	}

	int k = 0;
	for(int i = 0; i < unq.size(); i++)
		if(occ[unq[i]] % 2 != 0)
			k++;
	int ans = 1;
	if(k <= 1) ans = 1;
	else{
		if(k % 2 == 0) ans = 2;
		else ans = 1;
	}

	if(ans == 1) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}
