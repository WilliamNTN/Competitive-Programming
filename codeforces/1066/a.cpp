
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 10123;
int l,v,p1,p2;
int t;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		cin>>l>>v>>p1>>p2;
		int total = l/v;
		int remove = p2/v - (p1-1)/v;
		cout<<total-remove<<endl;
	}
	return 0;
}
