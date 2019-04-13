#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL n;
LL vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(LL i = 0; i < n; i++)
		cin>>vals[i];

	LL len = 1;
	LL maxLen = 1;
	for(int i = 1; i < n; i++){
		if(vals[i] <= (2*vals[i-1])){
			len++;
			maxLen = max(maxLen,len);
		}else{
			len = 1;
		}
	}

	cout<<maxLen<<endl;
	return 0;	
}
