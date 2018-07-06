#include <bits/stdc++.h>
using namespace std;
#define LL long long int



int n;
int vals[201234];
int solve(int pos, vector<int> sofar){
	if(pos > n-1) return 0;

	int check = 1;
	for(int i = 0; i < sofar.size(); i++){
		int diff = abs(sofar[i] - vals[pos]);
		if(diff & (diff-1) != 0){
			check = 0;
			i = sofar.size();
		}
	}
	int ans = 0;
	ans = max(ans,solve(pos+1,sofar));
	if(check){
		sofar.push_back(vals[pos]);
		ans = max(ans,solve(pos+1,sofar));
	}

	return ans;

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0; i<n; i++) cin>>vals[i];
	vector<int> go;
	cout<<solve(0,go)<<endl;

	return 0;
}
