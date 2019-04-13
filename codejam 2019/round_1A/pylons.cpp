#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int t;
int r,c;
set<pii> used;
bool solve(int x, int y,vector<pii>&vec){
	if((vec.size()+1) == (r*c)){
		vec.pb(mp(x,y));
		return true;
	}

	vec.pb(mp(x,y));
	used.insert(mp(x,y));
	for(int i = 1; i <= r; i++){
		if(i == x) continue;
		for(int j = 1; j <= c; j++){
			if(j == y) continue; 
			if(x == i || y == j || (x+y)==(i+j) || (x-y) == (i-j)) continue;
			if(used.find(mp(i,j)) != used.end()) continue;
			if(solve(i,j,vec))
				return true;
		}
	}
	vec.pop_back();
	used.erase(mp(x,y));
	return false;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		cin>>r>>c;
		vector<pii> vec;
		used.clear();
		cout<<"Case #"<<casen<<": ";
		if(solve(1,1,vec)){
			cout<<"POSSIBLE"<<endl;
			for(int i = 0; i < vec.size(); i++)
				cout<<vec[i].ff<<" "<<vec[i].ss<<endl;
		}else{
			cout<<"IMPOSSIBLE"<<endl;
		}
	}
	return 0;
}
