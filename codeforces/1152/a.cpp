#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int n,m,a,b;
int aEven,aOdd,bEven,bOdd;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	aEven = aOdd = bEven = bOdd = 0;
	for(int i = 0; i < n; i++){
		cin>>a;
		if(a%2 == 1)aOdd++;
		else aEven++;
	}
	for(int i = 0; i < m; i++){
		cin>>b;
		if(b%2 == 1) bOdd++;
		else bEven++;
	}

	cout<<min(aEven,bOdd) + min(aOdd,bEven)<<endl;
	return 0;
}
