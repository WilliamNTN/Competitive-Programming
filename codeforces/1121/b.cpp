#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1010;
int n;
int vals[maxN];
map<int,int> hashMap;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>vals[i];
		
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int sum = vals[i]+vals[j];
			hashMap[sum]++;
			ans = max(ans,hashMap[sum]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
