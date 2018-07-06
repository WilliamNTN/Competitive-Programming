#include <bits/stdc++.h>
using namespace std;

//time 5:17

int n,k;
int wanted[1010];
set<int> used;
map<int,int> want;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i=1; i<=(k); i++){
		int a1;
		cin>>a1;
		want[i] = a1;
		used.insert(a1);
	}

	for(int i=1; i<=k;i++){
		int t = 1;
		cout<<want[i]<<" ";

		for(int j=1;j<=(n*k) && t < n; j++){
			if(used.count(j) == 0){
				cout<<j<<" ";
				t++;
				used.insert(j);
			}
		}
		cout<<endl;
	}
	return 0;
}
