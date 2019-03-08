#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int c1,c2,c3,c4;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>c1>>c2>>c3>>c4;
	
	if(c1 != c4){
		cout<<0<<endl; return 0;
	}
	if(c3 && c1 == 0){
		cout<<0<<endl; return 0;
	}
	cout<<1<<endl;
	return 0;	
}
