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
int c[maxN];
int a[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <= n; i++){
		char x; cin>>x;
		c[i] = x - '0';
	}
	for(int i = 1; i <= n; i++){
		char x; cin>>x;
		a[i] = x - '0';
	}

	vector<int> clow;
	vector<int> acrobat;
	vector<int> both;
	vector<int> none;
	for(int i = 1; i<=n; i++){
		if(a[i] == 1 && c[i] == 1)
			both.pb(i);
		else if(c[i] == 1)
			clow.pb(i);
		else if(a[i] == 1)
			acrobat.pb(i);
		else
			none.pb(i);
	}
	


	return 0;
}
