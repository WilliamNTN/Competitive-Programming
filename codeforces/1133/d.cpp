#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;

int n;
double a[maxN],b[maxN];
map<pair<double,double>, int> cc;

double gcd(int a, int b){
	if(!a) return b;

	return gcd(b%a,a);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];

	for(int i = 0; i < n; i++)
		cin>>b[i];

	//d*a[i] + b[i] = 0
	//d*a[i] = -b[i]
	//d = -b[i]/a[i];

	int ans = 0;
	int dontCare = 0;
	for(int i = 0; i < n;i++){

		if(a[i] == 0 && b[i] == 0) dontCare++;
		else if(a[i] == 0) continue;
		else if(b[i] == 0){
			cc[mp(0,0)]++;
			ans = max(ans,cc[mp(0,0)]);
		}
		else{
			int g = gcd(-b[i],a[i]);
			int u = -b[i]/g;
			int d = a[i]/g;

			cc[mp(u,d)]++;
			ans = max(ans,cc[mp(u,d)]);
		}
	}

	cout<<ans + dontCare<<endl;
	return 0;
}
