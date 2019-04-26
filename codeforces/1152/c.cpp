#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL a,b,pr,cur;
LL gcd(LL a, LL b){
	if(a%b == 0) return b;
	return gcd(b,a%b);
}
LL lcm(a,b){
	return (a*b)/gcd(a,b);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b;

	return 0;
}
