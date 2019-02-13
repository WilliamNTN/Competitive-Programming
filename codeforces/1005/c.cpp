
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back	
#define mp make_pair

const int maxN = 120010;
LL vals[maxN];
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
	}
	set<LL> good;
	for(int i = 0; i < 31; i++){
		LL target = pow(2,i);
		set<LL> nice;
		for(int j = 0; j < n; j++){
			if(nice.find(target-vals[j]) != nice.end()){
				good.insert(vals[j]);
				good.insert(target-vals[j]);
			}
			nice.insert(vals[j]);
		}
	}

	int count = 0;
	for(int i = 0; i < n; i++){
		if(good.find(vals[i]) == good.end()) count++;
	}
	cout<<count<<endl;
	return 0;
}
