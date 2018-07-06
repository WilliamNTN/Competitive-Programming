#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define ff first
#define ss second


const int maxN = 101234;
int n;
pair<int,int> seg[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int a,b;
	cin>>a>>b;
	int min = a, max = b;
	seg[0] = make_pair(a,b);

	for(int i = 1; i<n; i++){
		int a,b;
		cin>>a>>b;
		if(a < min) min = a;
		if(b > max) max = b;
		seg[i] = make_pair(a,b);
	}

	for(int i = 0; i<n; i++)
		if(seg[i].ff <= min && seg[i].ss >= max){
			cout<<i+1<<endl;
			return 0;
		}

	cout<<-1<<endl;
	return 0;
}
