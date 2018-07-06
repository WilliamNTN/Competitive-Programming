#include <bits/stdc++.h>
using namespace std;

#define LL long long int
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int* dists = (int*)malloc(sizeof(int)*n);

	dists[0] = 0;
	int lastI = 1;
	for(int i=0; i<(n-1); i++){
		int a;
		cin>>a;
		int td = dists[i]+1;
		for(int j = lastI; j<=(i+a); j++){
			dists[j] = td;
			lastI = j+1;
		}
	}
   
   	cout<<dists[--n]<<endl;

	return 0;
}
