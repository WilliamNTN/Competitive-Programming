#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int n,k;
int t;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 0; i < n; i++){
			cout<<(char)('a'+(i%k));
		}
		cout<<endl;
	}
	return 0;
}
