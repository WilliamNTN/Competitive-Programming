#include <bits/stdc++.h>
using namespace std;
#define LL long long int

map<int,int> sure;
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int count = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<3; j++){
			int a;
			cin>>a;
			if(a){
				sure[i]++;
				if(sure[i] == 2) count++;
			}
		}
	}

	cout<<count<<endl;
	return 0;
}
