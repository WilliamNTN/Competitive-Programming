
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN =5050;
int n,m,k;
pll vals[maxN];
LL cs[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		LL a; cin>>a;
		vals[i] = mp(a,i);
	}
	cs[0] = vals[0].ff;
	for(int i = 1; i < n; i++){
		cs[i] = cs[i-1] + vals[i].ff;
	}
	sort(vals,vals+n);
	
	LL totalSum = 0;

	for(int i = n-1; i>=0 && k; i--){
		int j = i;
		while(j >= 0){
			if(vals[i].ff - vals[j].ff + 1 == m) break;
			j--;
		}
		if(j >= 0 && vals[i].ff - vals[j].ff + 1 == m){
			while(j >= 0 && vals[j].ff == vals[j-1].ff) j--;
			int index1 = vals[i].ss;
			int index2 = vals[j].ss;
			if(index1 < index2){
				swap(index1,index2);
			}
			totalSum += cs[index1];
			if(index2 > 0) totalSum -= cs[index2-1];
			k--;
			i = j;
		}
	}

	cout<<totalSum<<endl;
	return 0;
}
