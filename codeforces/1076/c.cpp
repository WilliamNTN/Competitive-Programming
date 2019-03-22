#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int d;
int t;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	double error = pow(10,-6);
	cin>>t;
	while(t--){
		cin>>d;
		if(d==0){
			cout<<"Y "<<0<<" "<<0<<endl; continue;
		}
		double l = 0, r = 2;
		double ans = -1;
		int times = 100000;
		while(times--){
			double b = (l+r)/2.0;
			double a = d-b;
			if(a*b < d){
				l = b;
			}else{
				r = b;
			}
			ans = b;
		}
		double a = d-ans;
		if((abs((a+ans) - (a*ans))>error) || abs((a+ans)-d) > error){
			cout<<"N"<<endl;
		}
		else{
			cout<<fixed<<setprecision(9);
			cout<<"Y "<<a<<" "<<ans<<endl;
		}

	}

	return 0;
}
