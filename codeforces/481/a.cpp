#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> vals[55];
set<int> used;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		vals[i] = make_pair(a,0);
	}


	int count = 0;
	for(int i = n-1; i>=0; i--){
		if(used.count(vals[i].first) == 0){
			used.insert(vals[i].first);
			vals[i].second = 1;
			count++;
		}
	}

	cout<<count<<endl;
	for(int i=0; i<n; i++)
		if(vals[i].second == 1)
			cout<<vals[i].first<<" ";

	cout<<endl;


	return 0;
}
