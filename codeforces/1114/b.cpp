
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define pll pair<long long int, long long int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
int n,m,k;
LL vals[maxN];
LL sorted[maxN];
map<LL,LL> ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		sorted[i] = vals[i];
	}

	sort(sorted,sorted+n);
	LL totalSum = 0;
	for(int i = 0; i < (m*k); i++){
		totalSum += sorted[n-1-i];
		ans[sorted[n-1-i]]++;
	}

	int p = 0;
	int found = 0;
	vector<int> pos; k = k-1;
	while(k--){
		while(found != m){
			if(ans[vals[p]] > 0){
				ans[vals[p]]--;
				found++;
			}
			p++;
		}
		pos.pb(p);
		found = 0;

	}

	cout<<totalSum<<endl;
	for(int i = 0; i < pos.size(); i++){
		cout<<pos[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
