#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 0;
LL y,k,n;
LL x;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>y>>k>>n;
	LL start = y+1;
	if(start % k != 0){
		long double factor = (start*1.0/k*1.0);
		start = ceil(factor)*k;
	}
	if(start > n){
		cout<<-1<<endl; return 0;
	}
	for(start; start <= n; start +=k){
		cout<<start-y<<" ";
	}
	cout<<endl;	
	return 0;
}
