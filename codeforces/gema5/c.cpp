#include <bits/stdc++.h>
using namespace std;


int solve(int start, int n){

	int count = 0;
	for(int i=start; i<=n; i+=start){
		if(n-i == 0){
			count++;
		}
		if((n-i) > 0){
			count += solve(i,(n-i));
		}
	}

	return count;
}

int n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	cout<<solve(1,n)<<endl;
	return 0;
}
