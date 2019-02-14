#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1012345;
LL n,k;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	// x > k
	// X < n*k/1
	// 100 / 3 = 33 * 3 
	int lastK = n/k *k;
	int i = lastK < k? k+1 : lastK+1;
	do{
		if(i%k == 0){
			i++; continue;
		}
		if(((i/k)*(i%k)) == n){
			cout<<i<<endl;
			return 0;
		}
		i++;
	}while(i <= (LL)(n*k));

	return 0;
}
