#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL n;
LL x,y;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	cin>>x>>y;

	LL dista = max(x-1,y-1);
	LL distb = max(n-x,n-y);

	if(dista <= distb)
		cout<<"White"<<endl;
	else
		cout<<"Black"<<endl;

	return 0;
}
