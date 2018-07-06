#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n;
int vals[201234];

vector<int> maxSize(vector<int> a,vector<int> b, vector<int> c){
	if(a.size() > b.size() && a.size() > c.size()) return a;
	if(b.size() > a.size() && b.size() > c.size()) return b;
	return c;
}
// O(2^n)
vector<int> solve(int pos, vector<int> sofar){
	if(pos > n) return sofar;

	int check = 1;
	for(int i=0; i<sofar.size(); i++){
		int diff = abs(sofar[i] - vals[pos]);
		if(ceil(log2(diff)) != floor(log2(diff))){
			check = 0; i = sofar.size();
		}
	}

	vector<int> ans1,ans2;
	ans1 = solve(pos+1,sofar);
	if(check){
		vector<int> temp = sofar;
		temp.push_back(vals[pos]);
		ans2 = solve(pos+1,temp);
	}

	return maxSize(sofar,ans1,ans2);

}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>vals[i];

	vector<int> go;
	vector<int> ans = solve(1,go); 

	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
