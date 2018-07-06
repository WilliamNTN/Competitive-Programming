#include <bits/stdc++.h>
using namespace std;
#define LL long long int

string s;
int vals[101234];
int m;
int l,r;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s>>m;
	int sum = 0;
	vals[0] = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == s[i-1]) sum++;
		vals[i] = sum;
	}
	while(m--){
		cin>>l>>r; l--; r--;
		cout<<vals[r] - vals[l]<<endl;
	}
	return 0;
}
