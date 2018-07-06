#include <bits/stdc++.h>
using namespace std;
#define LL long long int
const int NN = 101234;

int n,m;
int vals[NN];
int acc[NN];
int q[NN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>vals[i];
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>q[i];

	acc[0] = vals[0];
	for(int i = 1; i<n; i++){	
		acc[i] = acc[i-1] + vals[i];
	}

	for(int i = 0; i<m; i++){
		int s = q[i];
		int l = 0, r = n-1;
		int ans = -1;

		while( l <= r){
			int m = (l+r)/2;
			if(acc[m] >= s){
				ans = m;
				r = m-1;
			}
			else
				l = m+1;
		}
		
		cout<<ans+1<<endl;
	}

	return 0;
}
