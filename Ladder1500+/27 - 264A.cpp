#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n;
string s;
LL numbers[1012345];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	n = s.size();

	LL L = 0, R = (n-1);
	LL print = 0;
	for(LL i = 0; i<n; i++){
		if(s[i] == 'l'){
			numbers[R] = i;
			R--;
		}
		else{
			numbers[L] = i;
			L++;
			cout<<i+1<<endl;
			print++;
		}
	}
		
	for(print; print < n; print++)
		cout<<numbers[print]+1<<endl;
}