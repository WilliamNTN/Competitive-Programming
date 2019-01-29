
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;

double a,b,c,d;

LL gcd(LL a, LL b){

	if(a == 0) return b;

	return gcd(b%a,a);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b; // monitor
	cin>>c>>d; // movie

	//one of these needs to be one
	double hRatio = a/c;
	double vRatio = b/d;
	double goRatio = hRatio <= vRatio ? hRatio : vRatio;

	c *= goRatio;
	d *= goRatio;

	double monitorArea = a * b;
	double movieArea = c * d;

	//TODO: result(movieArea/monitorArea);
	return 0;
}
