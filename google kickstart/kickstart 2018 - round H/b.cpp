
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 5011010;
int t;
int n;
string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int i = 1; i <=t; i++){
		cin>>n>>s;
		int windowSize = ceil(n/2);
		int end = 0;
		LL thisSum = 0;
		for(end; end < windowSize; end++)
			thisSum += s[end]-'0';

		LL maxSum = thisSum;
		for(end; end < n; end++){
			thisSum -= s[end-windowSize]-'0';
			thisSum += s[end] - '0';
			maxSum = max(maxSum,thisSum);
		}

		cout<<"Case #"<<i<<": "<<maxSum<<endl;
	}
	return 0;
}
