#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
LL mod = pow(10,9)+7;
string s;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	LL n = s.size();
	LL aLeft = 0;
	int position = 0;
	LL ans = 0;
	LL totalA = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'a'){
			totalA = (totalA+1)%mod;
		}
	}	
	while(position < n){
		while(position < n && s[position] != 'b'){
			if(s[position] == 'a') aLeft++;
			position++;
		}
		while(position < n && s[position] == 'b') position++;
		LL aRight = 0;
		while(position < n && s[position] != 'b'){
			if(s[position] == 'a') aRight++;
			position++;
		}
		LL l = pow(2,aLeft)-1;
		ans = (ans + ((l%mod)*(aRight%mod))%mod)%mod;
		aLeft += aRight;
		aRight = 0;
	}
	cout<<((ans%mod)+(totalA%mod))%mod<<endl;
	return 0;
}