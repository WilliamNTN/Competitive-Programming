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
int mods[maxN];
int k;
map<int,int> used;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		mods[i] = vals[i]%k;
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		int thisValue = mods[i];
		int nextValue = ((k-thisValue)%k);
		if(used[nextValue]>0){
			ans++;
			used[nextValue]--;
		}
		else
			used[thisValue]++;
	}
	cout<<ans*2<<endl;

	return 0;
}
