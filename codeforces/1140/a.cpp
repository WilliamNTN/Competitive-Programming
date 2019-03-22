#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 10123;
int n;
int vals[maxN];
set<int> toRead;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>vals[i];


	int ans = 0;
	for(int i = 1; i <= n;){
		ans++;
		toRead.insert(vals[i]);
		toRead.erase(i);
		while(toRead.size()){
			i++;
			toRead.insert(vals[i]);
			toRead.erase(i);
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
