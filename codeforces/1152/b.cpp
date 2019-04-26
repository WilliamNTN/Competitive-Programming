#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int x;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>x;
	vector<int> ans;
	int op = 0;
	while(x > 1){
		int n = ceil(log(x)/log(2));
		x = x ^ (int)(pow(2,n)-1);
		ans.pb(n);
		op++;
		int k = ceil(log(x)/log(2));
		if(x == (pow(2,k)-1)) break;
		x++;
		op++;
		k = ceil(log(x)/log(2));
		if(x == (pow(2,k)-1)) break;

	}
	cout<<op<<endl;
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
