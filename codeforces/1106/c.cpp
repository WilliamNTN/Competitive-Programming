
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
LL n;
LL vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	sort(vals,vals+n);
	int pt0 = 0, pt1 = n-1;
	LL total = 0;

	while(pt0 < pt1){
		total += pow(vals[pt0] + vals[pt1],2);
		pt0++;
		pt1--;
	}

	cout<<total<<endl;
	return 0;
}
