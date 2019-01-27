
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 550;
int q;
int l1,r1,l2,r2;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>q;
	while(q--){
		cin>>l1>>r1>>l2>>r2;
		int a,b;
		a = l1;
		b = l2;
		if(a == b) b++;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
