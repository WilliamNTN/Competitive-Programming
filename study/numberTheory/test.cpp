#include <bits/stdc++.h>
using namespace std;
#define LL long long int

vector<int> primes;
int limits[3];

void solve(int i, int e, int d){
	if(i == primes.size()) cout<<d<<endl;

	solve(i+1,0,d);
	if(e <= limits[i])
		solve(i,e+1,d*primes[i]);


}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);

	limits[0] = 1; limits[1] = 2; limits[2] = 1;

	solve(0,0,1);
	return 0;
}
