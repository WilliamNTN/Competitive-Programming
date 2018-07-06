#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n;
int vals[102134];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++) cin>>vals[i];
	sort(vals,vals+n);
	int p1 = 0, p2 = n-1;

	while(vals[p2] <= 2*vals[p1]){
		//todo
	}

	return 0;
}
