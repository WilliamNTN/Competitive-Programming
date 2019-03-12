#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 5050;
int n,k;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;

	int ans = n+1 + n;
	int left = k-1;
	int right = n-k;
	if(left <= right){
		ans += 2* left + right;
	}else{
		ans += 2*right + left;
	}
	cout<<ans<<endl;
	return 0;
}
