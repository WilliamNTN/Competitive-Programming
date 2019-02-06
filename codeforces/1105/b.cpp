
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;

string s;
int n,k;

map<char,int> ansCount;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	cin>>s;
	int ans = 0;

	
	int count = 0;
	for(int i = 0; i < n; i++){
		if(count == 0){
			count++;
		}
		else if(s[i] == s[i-1]){
			count++;
		}
		else
			count = 1;

		if(count == k){
			ansCount[s[i]]++;
			ans = max(ans,ansCount[s[i]]);
			count = 0;
		}
	}

	cout<<ans<<endl;

}
