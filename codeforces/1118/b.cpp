#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
int n;
int vals[maxN];
pair<int,int> here[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <=n; i++)
		cin>>vals[i];

	here[1].ff = vals[1];
	here[1].ss = 0;
	for(int i = 2; i <=n; i++){
		here[i].ff = here[i-1].ff;
		here[i].ss = here[i-1].ss;
		if(i%2 == 0)
			here[i].ss += vals[i];
		else
			here[i].ff += vals[i];
	}

	int even = 0, odd = 0;
	int ans = 0;
	for(int i = n; i > 1; i--){
		if((here[i-1].ff + even) == (here[i-1].ss + odd))
			ans++;
		if(i%2 == 0)
			even+=vals[i];
		else
			odd+=vals[i];

	}
	if(even == odd) ans++;
	cout<<ans<<endl;
	return 0;
}
