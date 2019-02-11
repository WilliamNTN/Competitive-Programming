
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

vector<LL> primeFactors(LL x){
	vector<LL> res;
	while(x%2 == 0){
		res.pb(2);
		x = x/2;
	}
	for(LL i = 3; i <= sqrt(x); i+=2){
		
		while(x % i == 0){
			res.pb(i);
			 x = x/i;
		}
	}
	if(x > 2)
		res.pb(x);

	return res;
}

const LL maxN = 0;
LL n,b;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>b;

	vector<LL> primes = primeFactors(b);
	map<LL,LL> exp;
	for(LL i = 0; i < primes.size(); i++)
		exp[primes[i]]++;

	set<LL> done;

	LL ans = n;

	for(LL i = 0; i < primes.size(); i++){
		if(done.find(primes[i]) != done.end()) continue;
		LL cumSum = 0;
		for(LL j = 1; pow(primes[i],j) <= n; j++)
			cumSum += n/pow(primes[i],j);

		cumSum /= exp[primes[i]];
		done.insert(primes[i]);
		ans = min(ans,cumSum);
	}

	cout<<ans<<endl;
	return 0;
}
