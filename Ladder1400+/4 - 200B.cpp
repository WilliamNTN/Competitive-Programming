#include <bits/stdc++.h>
using namespace std;


//time 3:00

int n;
double ai,sum;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	sum = 0;
	for(int i=0;i<n;i++){
		cin>>ai;
		sum += ai;
	}

	cout<<fixed<<setprecision(12)<<sum/n<<endl;

	return 0;
}
