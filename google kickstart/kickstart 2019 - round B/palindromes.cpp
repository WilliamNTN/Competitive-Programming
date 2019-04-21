#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int t;
int n,q,l,r;
char vals[maxN];
map<char,int> hashMap;
set<char> present;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		cin>>n>>q;
		for(int i = 1; i <=n; i++)
			cin>>vals[i];

		int ans = 0;
		while(q--){
			cin>>l>>r;
			hashMap.clear();
			present.clear();
			for(int i = l; i <= r; i++){
				hashMap[vals[i]]++;
				present.insert(vals[i]);
			}
			int nOdd = 0;
			set<char>::iterator it;
			for(it = present.begin(); it != present.end(); it++){
				int val = hashMap[*it];
				if(val%2 != 0) nOdd++;
			}

			if((r-l+1)%2 == 0){
				if(nOdd == 0) ans++;
			}else{
				if(nOdd == 1) ans++;
			}
		}
		cout<<"Case #"<<casen<<": "<<ans<<endl;
	}
	return 0;
}
