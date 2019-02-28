#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int vals[maxN];
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int positive = 0, negative = 0, zero = 0;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		if(vals[i] > 0) positive++;
		else if(vals[i] < 0) negative++;
		else zero++;
	}
	if(positive >= ceil(n/2.0))
		cout<<1<<endl;
	else if(negative >= ceil(n/2.0))
		cout<<-1<<endl;
	else
		cout<<0<<endl;


	return 0;
}
