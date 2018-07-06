#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,cc;
int h,m;
int lh,lm, mx;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	cc = 1;
	mx = 1;
	lh = lm = -1;
	while(n--){
		cin>>h>>m;
		if(h == lh && m == lm)cc++;
		else cc = 1;
		if(cc > mx) mx = cc;
		lh = h; lm = m;
	}

	cout<<mx<<endl;
	return 0;
}
