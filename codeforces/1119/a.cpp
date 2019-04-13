#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 300300;
int n;
int vals[maxN];
map<int,int> firstSeen;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <=n; i++)
		cin>>vals[i];
	int count = 0;
	vector<int> done;
	int ans = 0;
	for(int i = 1; i <=n; i++){
		if(firstSeen[vals[i]] == 0){
			firstSeen[vals[i]] = i;
			count++;
			if(count <= 2)
				done.pb(vals[i]);
		}
		for(int j = 0; j < done.size(); j++)
			if(done[j] != vals[i])
				ans = max(ans,i - firstSeen[done[j]]);
	}

	cout<<ans<<endl;
	return 0;
}
