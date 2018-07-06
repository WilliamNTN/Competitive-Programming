#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int l = 1, r = 10;
	int res;
	int tr = 4;
	int m;
	while(tr--){ 
		m = (l+r)/2;
		cout<<m<<endl;
		if(!tr)
			return 0;
		fflush(stdout);
		cin>>res;
		if(res == 2){
			return 0;
		}
		if(res == 1){
			l = m+1;
		}
		else{
			r = m-1;
		}
	}
	return 0;
}
