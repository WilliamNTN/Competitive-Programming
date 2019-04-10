#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


const int maxN = 110;
LL t,n,l;
LL vals[maxN];
map<LL,char> hashMap;
map<pair<LL,LL>,bool> dp;

vector<LL> primeFactors(LL x){
	vector<LL> ans;
	while(x%2 == 0){
		ans.pb(2);
		x = x/2;
	}

	for(LL i = 3; i*i <= (x); i+=2){
		while(x % i == 0){
			ans.pb(i);
			 x = x/i;
		}
	}

	if(x > 2)
		ans.pb(x);

	return ans;
}

bool solve(int position, LL carry, vector<LL> &fac){
	if(position == l){
		fac.pb(carry);
		return true;
	}
	if(dp.find(mp(position,carry)) != dp.end())
		return false;
	vector<LL> res = primeFactors(vals[position]);
	if(res[0] == carry){
		if(dp.find(mp(position+1,res[1])) == dp.end()){
			fac.pb(carry);
			if(solve(position+1,res[1],fac))
				return true;
			fac.pop_back();
		}
	}
	if(res[1] == carry){
		if(dp.find(mp(position+1,res[0])) == dp.end()){
			fac.pb(carry);
			if(solve(position+1,res[0],fac))
				return true;
			fac.pop_back();
		}
	}
	dp[mp(position,carry)] = false;
	return false;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		cin>>n>>l;
		for(int i = 0; i < l; i++)
			cin>>vals[i];
		dp.clear();
		vector<LL> fac;
		vector<LL> res = primeFactors(vals[0]);
		fac.pb(res[1]);
		if(!solve(1,res[0],fac)){
			fac.clear();
			fac.pb(res[0]);
			solve(1,res[1],fac);
		}

		vector<LL> aux(fac.begin(),fac.end());
		sort(aux.begin(),aux.end());

		hashMap.clear();
		hashMap[aux[0]] = 'A';
		int add = 1;
		for(int i = 1; i < aux.size(); i++){
			if(aux[i] == aux[i-1]) continue;
			hashMap[aux[i]] = ('A' + add);
			add++;
		}
		cout<<"Case #"<<casen<<": ";
		for(int i = 0; i < fac.size(); i++){
			cout<<hashMap[fac[i]];
		}
		cout<<endl;
	}
}
