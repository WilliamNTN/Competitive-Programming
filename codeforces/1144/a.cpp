#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int n;
string s;
map<char,int> hashMap;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	while(n--){
		cin>>s;
		hashMap.clear();
		bool ans = true;
		char small = 'z';
		char great = 'a';
		for(int i = 0; i < s.size(); i++){
			hashMap[s[i]]++;
			if(hashMap[s[i]] > 1)
				ans = false;
			if(s[i] > great)
				great = s[i];
			if(s[i] < small)
				small = s[i];
		}
		int distance = great-small+1;
		if(!ans || distance != s.size())
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}
