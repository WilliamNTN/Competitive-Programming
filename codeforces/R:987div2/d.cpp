#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,m,k,s;
int products[101234];
vector<int> graph[101234];
map<pair<int,int>,int> dists;


void fw(){

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <=n; i++){
			for(int j = 1; j<=n; j++){
				int distij;
				if(dists.find(make_pair(i,j)) == dists.end())
					distij = 0x3f3f3f3f;
				else
					distij = dists[make_pair(i,j)];

				int distik;
				if(dists.find(make_pair(i,k)) == dists.end())
					distik = 0x3f3f3f3f;
				else
					distik = dists[make_pair(i,k)];

				int distkj;
				if(dists.find(make_pair(k,j)) == dists.end())
					distkj = 0x3f3f3f3f;
				else
					distkj = dists[make_pair(k,j)];

				if(distij > distik + distkj)
					dists[make_pair(i,j)] = distik + distkj;
			}
		}
	}
}

int getSum(int a){

	vector<pair<int,int> > t; // dist,city;

	for(int i = 1; i<= n; i++){
		int thisDist;
		if(dists.find(make_pair(a,i)) != dists.end())
			thisDist = dists[make_pair(a,i)];
		else
			thisDist = 0x3f3f3f3f;
		t.push_back(make_pair(thisDist,products[i]));
	}

	sort(t.begin(), t.end());


	int nused = 0,sum = 0;
	set<int> used;
	for(int i = 0; i < t.size(); i++){
		if(used.count(products[t[i].second]) == 0){
			used.insert(products[t[i].second]);
			nused++;
			sum += t[i].first;

			if(nused == s)
				return sum;
		}
	}
	return sum;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>k>>s;
	for(int i=1;i<=n;i++) cin>>products[i];
	if(n == 1){
		cout<<0<<endl; return 0;
	}
	while(m--){
		int u,v;
		cin>>u>>v;
		dists[make_pair(u,v)] = 1;
		dists[make_pair(v,u)] = 1;

		dists[make_pair(u,u)] = dists[make_pair(v,v)] = 0;
	}
	fw();
	
	for(int i = 1; i<=n; i++){
		cout<<getSum(i)<<" ";
	}
	cout<<endl;
	return 0;
}
