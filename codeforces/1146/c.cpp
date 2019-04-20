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
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		ans = -1;
		cin>>n;
		
		int pivot = n/2;
		int ans = -1
		while(pivot >= 1 && pivot <= n){
			ask(pivot);
			cin>>inp;
			
			if(ans == -1){
				int size = pivot/2;
				pivot += size;
				ans = inp;
			}else if(inp >= ans){
				
			}
		}

	}
	return 0;
}
