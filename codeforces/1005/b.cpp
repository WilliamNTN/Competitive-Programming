
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;

string s,t;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s>>t;

	int pts = s.size()-1;
	int ptt = t.size()-1;

	while(pts >=0 && ptt >= 0 && s[pts] == t[ptt]){
		pts--; ptt--;
	}

	cout<<pts+1+ptt+1<<endl;
	return 0;
}
