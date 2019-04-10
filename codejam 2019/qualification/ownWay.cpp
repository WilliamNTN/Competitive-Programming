#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 50050;
int t;
int n;
string p;
set<pair<pii,pii>> used;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		cin>>n>>p;
		cout<<"Case #"<<casen<<": ";
		for(int i = 0; i < p.size(); i++)
			if(p[i] == 'S')
				cout<<"E";
			else
				cout<<"S";
		cout<<endl;
	}
	return 0;
}
