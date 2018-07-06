#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,m;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	int freq[m];
	LL a;
	for(LL i =0; i<n; i++){
		for(LL j=0; j<m; j++){
			cin>>a;
			if(a == 0)
				freq[j] = 1;
		}
	}

	for(LL i = 0; i<m; i++){
		if(freq[i] != 1){
			cout<<"N"<<endl;
			return 0;
		}
	}
	cout<<"S"<<endl;
	return 0;
}
