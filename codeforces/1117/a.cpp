#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int n;
int vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
	}
	int maxVal = vals[0];
	for(int i  = 1; i < n; i++)
		maxVal = max(maxVal,vals[i]);

	int ans = 0;
	int count = 0;
	for(int i = 0; i < n; i++){
		if(vals[i] == maxVal){
			count++;
			ans = max(ans,count);
		}else{
			count = 0;
		}
	}

	cout<<ans<<endl;
	return 0;
}
