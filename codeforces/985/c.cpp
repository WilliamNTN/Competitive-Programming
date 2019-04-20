#include <bits/stdc++.h>
using namespace std;

#define LL long long int


LL n,k,l;
LL vals[101234];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>l;
	int total = n*k;
	for(int i=0;i<total; i++){
		cin>>vals[i];
	}
	sort(vals,vals+total);

}
