#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n;
LL vals[101234];
LL check[4];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(LL i=0;i<n;i++){
		cin>>vals[i];
		if(vals[i]==25){
			check[0]++;
		}
		else if(vals[i]==50){
			if(check[0] >= 1)
				check[0]--;
			else{
				cout<<"NO"<<endl;
				return 0;
			}
			check[1]++;
		}
		else if(vals[i]==100){
			if(check[1]>=1 && check[0]>=1){
				check[1]--; check[0]--;
			}
			else if(check[0]>=3)
				check[0] -= 3;
			else{
				cout<<"NO"<<endl;
				return 0;
			}

		}
	}

	cout<<"YES"<<endl;



	return 0;
}
