
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n;
int vals[maxN];
int x;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	
	x = 1;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>vals[i];
	}

	LL cost = 0;
	for(int i = 1; i <= n; i++){
		cost += vals[i] * (abs(x-i) + abs(i-1) + abs(x-1));
		cost += vals[i] * (abs(x-1) + abs(1-i) + abs(i-x));
	}

	cout<<cost<<endl;

	return 0;
}
