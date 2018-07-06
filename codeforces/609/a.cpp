#include <bits/stdc++.h>
using namespace std;

int n,m;
int cap[101];


bool compare(const int a, const int b){
	return a > b;
}

int main(){

	cin>>n>>m;

	for(int i=0;i<n;i++)
		cin>>cap[i];

	sort(cap,cap+n,compare);

	int soma = 0,i=0;

	while(soma < m){
		soma += cap[i];
		i++;
	}

	cout<<i<<endl;
	return 0;
}