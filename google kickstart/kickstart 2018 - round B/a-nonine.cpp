

// Correct for small
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;

LL t;
LL f,l;

LL solve(LL val){

	vector<int> digits;
	LL n = val;

	while(n){
		digits.pb(n%10);
		n /=10;
	}

	LL ans = 0;

	for(LL i = val-digits[0]; i <= val; i++){
		if(i%9 == 0) continue;
		int check = 1;
		LL num = i;
		while(num){
			int d = num%10;
			num /=10;
			if(d == 9) check = 0;
		}
		if(check) ans++;
	}

	LL c = 0;
	for(int i = 1; i < digits.size(); i++){
		c += digits[i]*pow(9,i);
	}

	ans += (8*c)/9;
	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	int count = 1;
	while(t--){
		cin>>f>>l;
	
		LL ans = solve(l) - solve(f) + 1;

		cout<<"Case #"<<count++<<": "<<ans<<endl;
	}
	return 0;
}
