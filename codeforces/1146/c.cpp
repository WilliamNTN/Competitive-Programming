#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int t,n,ans;
int maxDist1,maxDistNode,cur,pre;

int ask(int size1, int size2, int start1, int end1, int start2, int end2){
	cout<<size1<<" "<<size2<<" ";
	for(int i = start1; i <= start1; i++)
		cout<<i<<" ";
	for(int i = start2; i <= end2; i++)
		cout<<i<<" ";
	cout<<endl;
	cout.flush();
	int ret;
	cin>>ret;
	return ret;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		ans = -1;
		cin>>n;
		
		int l = 2, r = n;
		maxDist1 = ask(1,n-1,1,1,l,r);
		pre = maxDist1;
		maxDistNode = -1;
		if(n == 2){
			cout<<-1<<" "<<maxDist1<<endl;
			continue;
		}
		while(l < r){
			int middle = (l+r)/2;
			cur = ask(1,middle-l+1,1,1,l,middle);
			if(cur < pre){
				l = middle+1;
			}else
				r = middle;

			maxDistNode = r;
		}
		cout<<1<<" "<<n-1<<" "<<maxDistNode<<" ";
		for(int i = 1; i <=n; i++){
			if(i == maxDistNode) continue;
			cout<<i<<" ";
		}
		cout<<endl;
		cout.flush();
		cin>>ans;
		cout<<-1<<" "<<ans<<endl;
	}
	return 0;
}
