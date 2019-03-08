
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 7003;

int t,n;

LL nChoosek( int a, int b )
{
    if (b > a) return 0;
    if (b * 2 > a) b = a-b;
    if (b == 0) return 1;

    LL result = a;
    for( int i = 2; i <= b; ++i ) {
        result *= (a-i+1);
        result /= i;
    }
    return result;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	int count = 1;
	while(t--){
	
		cin>>n;
		map<LL,LL> in;
		LL vals[maxN];
		int z;
		for(int i = 0; i < n; i++){
			cin>>vals[i];
			if(vals[i] == 0) z++;
		}

		sort(vals,vals+n);
		LL ans = 0;

		for(int i = n-1; i>=1; i--){
			for(int j = i-1; j >=0; j--){
				ans += in[vals[i]*vals[j]];
			}
			in[vals[i]]++;
		}
		ans += (nChoosek(z,3)*(n-z));
		cout<<"Case #"<<count++<<": "<<ans<<endl;
	}

	return 0;
}
