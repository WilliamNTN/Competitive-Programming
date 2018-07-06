#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int x,y,a,b;
int occ;
vector<int> v,p;
vector<pair<int,int> > solutions;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>x>>y>>a>>b;

	for(int i = a; i<=x; i++){
		for(int j = b; j<=y; j++){
			if(i > j)
				solutions.push_back(make_pair(i,j));
		}
	}

	sort(solutions.begin(), solutions.end());
	cout<<solutions.size()<<endl;
	for(int i = 0; i<solutions.size(); i++)
		cout<<solutions[i].first <<" " << solutions[i].second<<endl;
	return 0;
}
