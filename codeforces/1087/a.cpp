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
string r;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	r = s;
	int pt = 0, pt1 = s.size()-1;
	int pos = s.size()-1;
	if(s.size()%2 != 0){
		r[pos--] = s[pt];
		pt++; 
	}
	while(pt<pt1){
		r[pos--] = s[pt1];
		pt1--;
		r[pos--] = s[pt];
		pt++;
	}
	cout<<r<<endl;
	return 0;
}
