
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 130;
int n;
int divisors[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>divisors[i];

	sort(divisors,divisors+n);

	int x,y;
	y = divisors[n-1];

	int lastCut = y;
	for(int i = n-2; i >= 0; i--){
		if(y%divisors[i] == 0 && divisors[i] != lastCut)
			lastCut = divisors[i];
		else{
			x = divisors[i]; break;
		}
	}

	cout<<x<<" "<<y<<endl;
	return 0;
}
