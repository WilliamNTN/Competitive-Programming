#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1010;
int n,k;
int vals[maxN];
int total;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	total = 0;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		total += vals[i];
	}	

	
	return 0;
}
