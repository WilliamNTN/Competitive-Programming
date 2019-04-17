#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL vals[4];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	for(int i = 0; i < 4; i++)
		cin>>vals[i];

	sort(vals,vals+4);
	/*
	a + b = vals[0]
	a + c = vals[1]
	b + c = vals[2]

	a = vals[0] - b
	vals[0] - b + c = vals[1]  c = vals[1] - vals[0] + b
	b + vals[1] - vals[0] + b = vals[2]
	2b = vals[2] - vals[1] + vals[0] (first)	

	*/


	LL a,b,c;

	b = (vals[2] - vals[1] + vals[0])/2;
	a = vals[0] - b;
	c = vals[1] - a;

	cout<<a<<" "<<b<<" "<<c<<endl;

	return 0;
}
