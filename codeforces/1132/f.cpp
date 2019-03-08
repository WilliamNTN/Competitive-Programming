#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 550;
string s;
int n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	for(int i = 1; i < s.size();){
		if(s[i] == s[i-1])
			s = s.substr(0,i) + s.substr(i+1);
		else
			i++;
	}

	
	return 0;
}
