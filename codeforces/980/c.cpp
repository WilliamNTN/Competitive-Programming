#include <bits/stdc++.h>
using namespace std;
#define LL long long int
int n,k;
int vals[101234];
vector<int> arrays[260];

bool sortVectors(const vector<int> a, const vector<int> b){
	for(int i = 0; i<a.size(); i++){
		if(a[i] < b[i]) return true;
		if(b[i] < a[i]) return false;
	}

	return true;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>vals[i];

	for(int g = 1; g <= k; g++){
		for(int i = 0; i<n; i++){
			arrays[g-1].push_back( ((vals[i]/g))*g);
		}
	}

	sort(arrays,arrays+k,sortVectors);
	for(int i = 0; i<k; i++){
		for(int j = 0; j<arrays[i].size(); j++){
			cout<<arrays[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
