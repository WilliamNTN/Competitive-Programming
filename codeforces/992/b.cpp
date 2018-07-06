#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

const int maxN = 0;


// gcd(a,b) * lcm(a,b) = a*b
// x*y = a*b
// H = a*b
//
LL l,r,x,y;

LL gcd(LL a, LL b){ //O(log a*b)
	if(a%b == 0) return b;

	return gcd(b,a%b);
}


int lcm(LL a, LL b){	// O(log a*b);
	return ((a*b)/(gcd(a,b)));
}

vector<LL> divisors(LL n){

	vector<LL> ans;

	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			ans.pb(i);
			if(n/i != i)
				ans.pb(n/i);
		}
	}

	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>l>>r>>x>>y;

	LL H = x*y;

	vector<LL> div = divisors(H);
	int count = 0;

	for(int i = 0; i < div.size(); i++){
		LL a = div[i];
		LL b = H/div[i];

		if(l <= a && l <= b && r >= a && r >= b && lcm(a,b) == y && gcd(a,b) == x){
			count++;
		}
	}

	cout<<count<<endl;
	return 0;
}
