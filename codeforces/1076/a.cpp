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
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	int i;
	for(i = 0; i < n-1; i++){
		if((s[i]-'a') > (s[i+1]-'a')){
			break;
		}
	}
	cout<<s.substr(0,i) + s.substr(i+1)<<endl;
	return 0;
}
