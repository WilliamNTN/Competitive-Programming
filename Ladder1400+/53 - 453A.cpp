
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
double times, faces;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>faces>>times;

	double ev = 0;
	for(int i = 1; i <= faces; i++){
		ev += i * (1.0/faces);
	}
	cout<<fixed<<setprecision(20)<<ev*times<<endl;

	return 0;
}
