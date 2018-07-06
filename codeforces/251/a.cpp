#include <bits/stdc++.h>
using namespace std;
#define LL long long int
const int NN = 101234;

int n,d;
int points[NN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>d;
	for(int i = 0; i<n;i++)
		cin>>points[i];

	int sum = 0;

	int i = 0;
	while(i < n-2){
		int dist = d - vals[i];
		int ans = i;

		int l = i, r = n-1;
		
		while(l <= r){
			int m = (l+r)/2;
			if(vals[m] <= dist){
				ans = m;
				l = m+1;
			}
			else	r = m-1;
		}

		sum += coef(ans-i+1,3);
		i = ans+1;
	}

	return 0;
}
