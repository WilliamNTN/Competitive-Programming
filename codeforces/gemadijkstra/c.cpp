#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n;
pair<vector<pair<int,int> >,int> vals[202134];		//ff.ff = number, ff.ss = index ss == sum

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; i++){
		int s; cin>>s;
		set<int> used;
		for(int j=1; j<=s; j++){
			int a;
			cin>>a;
			if(used.count(a) == 0){
				used.insert(a);
				(vals[i].ff).push_back(a,j);
			}
			vals[i].ss += a;
		}
	}

	return 0;
}
