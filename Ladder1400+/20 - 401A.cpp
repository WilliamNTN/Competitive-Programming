#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n,x;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int sum = 0;
	cin>>n>>x;

	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		sum += a;
	}

	int diff = abs(sum);

	int count = 0;
	while(diff > 0){
		if(diff <= x){
			count++;
			diff = 0;
		}
		else{
			count++;
			diff -=x;
		}
	}

	cout<<count<<endl;
	return 0;
}
