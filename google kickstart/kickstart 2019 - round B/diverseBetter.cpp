#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;

int t,n,s,ans,countVal,removed;
int vals[maxN];
map<char,vector<int>> indexes;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		cin>>n>>s;
		for(int i = 0; i < n; i++)
			cin>>vals[i];


		ans = countVal = removed = 0;
		indexes.clear();

		for(int i = 0; i < n; i++){
			if(indexes[vals[i]].size() < s){
				indexes[vals[i]].pb(i);
				countVal++;
			}else if(indexes[vals[i]].size()==s){
				int before = indexes[vals[i]][0]+1-removed;
				if((countVal+1-before) >= (countVal-s)){//drop
					countVal++;
					int limit = indexes[vals[i]][0];
					for(int j = removed; j <=limit ;j++){
						indexes[vals[j]].erase(indexes[vals[j]].begin());
						countVal--;
					}
					removed += before;
				}else{//eliminate
					countVal -= s;
					indexes[vals[i]].pb(i); // more than s, eliminated
				}
			}
			ans = max(ans,countVal);
		}

		cout<<"Case #"<<casen<<": "<<ans<<endl;

	}
	return 0;
}
