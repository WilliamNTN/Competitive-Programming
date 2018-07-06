#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second

const int maxN = 101234;


int n,m;
int vals[maxN];
map<int,int> ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	map<int,int> used;
	int diff = 0;
	for(int i = 1; i<=n; i++){
		cin>>vals[i];
		used[vals[i]]++;
		if(used[vals[i]] == 1)
			diff++;
	}

	ans[1] = diff;
	for(int i = 2; i<=n; i++){
		used[vals[i-1]]--;
		if(used[vals[i-1]] == 0) diff--;
		ans[i] = diff;
	}
		

	while(m--){
		int q; cin>>q;
		cout<<ans[q]<<endl;
	}

	return 0;
}