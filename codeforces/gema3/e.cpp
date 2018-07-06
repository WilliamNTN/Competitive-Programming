#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n,b;

	cin>>n>>b;
	long long int a = b-n;

	long long int res =((b*(b+1)/2) - (a*(a+1)/2));
	cout<<res<<endl;
	return 0;
}