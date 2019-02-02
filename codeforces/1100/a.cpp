
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n,k;
int vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	int tot1 = 0, tot2 = 0;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		if(vals[i] == 1) tot1++;
		else tot2++;
	}


	int ans = 0;

	for(int i = 0; i < k; i++){
		int this1 = tot1;
		int this2 = tot2;
		for(int j = i; j < n; j+=k){
			if(vals[j] == 1) this1--;
			else this2--;
		}
		ans = max(ans,abs(this1-this2));
	}
	cout<<ans<<endl;
	return 0;
}
