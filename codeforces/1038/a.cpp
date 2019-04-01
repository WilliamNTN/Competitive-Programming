#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int n,k;
string s;
map<char,int> hashMap;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k>>s;
	int ans = n+1;
	for(int i = 0; i < n; i++){
		hashMap[s[i]]++;
	}
	for(int i = 0; i < k; i++){
		ans = min(ans,hashMap[('A'+i)]);
	}
	cout<<ans*k<<endl;

	return 0;
}
