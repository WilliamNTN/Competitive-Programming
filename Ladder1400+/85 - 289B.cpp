#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,m,d;
int vals[10123];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>d;
	int k = n*m;
	for(int i=0; i< k; i++)
		cin>>vals[i];

	sort(vals,vals+k);

	int me = vals[k/2];
	int sum = 0;
	for(int i=0; i<k; i++){
		if(vals[i]%d != me%d){
			cout<<-1<<endl;
			return 0;
		}
		sum += (abs(vals[i]-me));
		cout<<"S: "<<sum<<endl;
	}

	cout<<sum/d<<endl;
	return 0;
}
