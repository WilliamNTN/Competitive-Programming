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

LL gcd(LL a, LL b){
	while(a != b){
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

bool solve(int position, LL carry, vector<LL> &fac){
	if(position == (l-1)){
		fac.pb(carry);
		return true;
	}
	vector<LL> res;
	res.pb(gcd(vals[position],vals[position+1]));
	res.pb(vals[position]/res[0]);
	if(res[0] == carry){
		
		fac.pb(carry);
		if(solve(position+1,res[1],fac))
			return true;
		fac.pop_back();
		
	}
	if(res[1] == carry){
		
		fac.pb(carry);
		if(solve(position+1,res[0],fac))
			return true;
		fac.pop_back();
		
	}
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
		vector<LL> fac;
		vector<LL> res;
		res.pb(gcd(vals[0],vals[1]));
		res.pb(vals[0]/res[0]);

		fac.pb(res[1]);
		if(!solve(1,res[0],fac)){
			fac.clear();
			fac.pb(res[0]);
			solve(1,res[1],fac);
		}
		fac.pb(vals[l-1]/fac[fac.size()-1]);

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
