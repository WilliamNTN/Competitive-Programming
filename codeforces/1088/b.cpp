#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int n,k;
int vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	sort(vals,vals+n);

	int index = 0;
	int sum = 0;
	for(int i = 0; i < k; i++){
		if(index >= n){
			cout<<0<<endl;
		}
		else{
			while(index < n && vals[index]-sum <= 0) index++;
			if(index == n) cout<<0<<endl;
			else{
				cout<<vals[index]-sum<<endl;
				sum += (vals[index]-sum);
			}
		}

	}
	return 0;
}
