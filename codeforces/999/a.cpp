#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 110;

int n,k;
int vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i = 0; i<n; i++) cin>>vals[i];


	int count = 0;
	int i;
	for(i = 0; i<n && vals[i] <= k; i++,count++);

	for(int j = n-1; j >=0 && j > i && vals[j] <= k; j--,count++);

	cout<<count<<endl;

	return 0;
}
