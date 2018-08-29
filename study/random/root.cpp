#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 501210;

int x,n;



double root(int x, int n){

	double lower = 0, upper = x;
	int check = 0;
	double ans = 0;

	while(!check){

		double middle = (lower+upper)/2;
		double t = pow(middle,n);

		if(abs(x-t)<=0.001){
			ans = middle; check = 1;
		}
		else{

			if(t > x){
				upper = middle;
			}
			else{
				lower = middle;
			}
		}
	}

	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>x>>n;

	while(x && n){

		cout<<root(x,n)<<endl;
		cin>>x>>n;
	}



	return 0;
}