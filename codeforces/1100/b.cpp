
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int n,m;
int vals[maxN];
vector<int> ans;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>m>>n;
	int totalDiff = 0;
	map<int,int> hash;

	for(int i = 0; i < n; i++){
		cin>>vals[i];
		vals[i]--;
	}

	for(int i = 0; i < n; i++){
		hash[vals[i]]++;
		if(hash[vals[i]] == 1)
			totalDiff++;
		if(totalDiff == m){
			ans.pb(1);
			for(int j = 0; j < m; j++){
				hash[j]--;
				if(hash[j] == 0) totalDiff--;
			}
		}
		else
			ans.pb(0);
	}
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i];
	cout<<endl;
	return 0;
}
