
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;

int x,y;
int n;
int door;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>x>>y;
	int lessEqual = 0;
	for(int i = 0; i < n; i++){
		cin>>door;
		if(door <= x) lessEqual++;
	}

	int ans = 0;
	if(x <= y)
		ans = ceil(lessEqual/2.0);
	else
		ans = n;

	cout<<ans<<endl;
	return 0;
}
