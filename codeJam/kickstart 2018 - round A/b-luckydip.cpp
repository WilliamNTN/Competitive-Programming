

//Correct for small and large

#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 20202;
const int maxK = 50505;

double vals[maxN];
double sums[maxN];
double probs[maxK];
int t;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	int count = 1;
	while(t--){
		int n,k;
		cin>>n>>k;
		memset(vals,0,sizeof(vals));
		memset(probs,0,sizeof(probs));
		for(int i = 0; i < n; i++)
			cin>>vals[i];

		sort(vals,vals+n);
		
		sums[0] = vals[0];
		for(int i = 1; i < n; i++)
			sums[i] = vals[i] + sums[i-1];

		probs[0] = sums[n-1]/(n*1.0);

		for(int i = 1; i <= k; i++){
			
			int index = upper_bound(vals,vals+n,probs[i-1]) - vals;
			double ans = probs[i-1]*index;
			ans += (sums[n-1]-sums[index-1]);
			probs[i] = ans/(n*1.0);
		}

		cout<<setprecision(6)<<fixed;
		cout<<"Case #"<<count++<<": "<<probs[k]<<endl;
	}
	return 0;
}
