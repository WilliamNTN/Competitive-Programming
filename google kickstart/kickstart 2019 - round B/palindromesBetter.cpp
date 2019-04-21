#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;	
int t,l,r,q,n,ans,nOdd;
char vals[maxN];
map<char,vector<int>> charCount;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		
		charCount.clear();
		ans = 0;
		cin>>n>>q;
		for(int i = 1; i <= n; i++){
		  cin>>vals[i];
		}
		
		for(int j = 0; j < 26; j++){
		  char c = 'A' + j; // each char
		  int thisCount = 0;
		  charCount[c].pb(0);
		  for(int i = 1; i<=n; i++){
		    if(vals[i] == c) thisCount++;
		    charCount[c].pb(thisCount);
		  }
		}
		while(q--){
		  nOdd = 0;
		  cin>>l>>r;
		  for(int j = 0; j <26; j++){
		    char c = 'A' + j;
		    int thisCount = charCount[c][r] - charCount[c][l-1];
		    if(thisCount%2 == 1)nOdd++;
		  }
		  
		  if((r-l+1)%2 == nOdd) ans++;
		}
		
		cout<<"Case #"<<casen<<": "<<ans<<endl;

	}
	return 0;
}