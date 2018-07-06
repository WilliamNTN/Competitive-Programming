#include <bits/stdc++.h>


using namespace std;


bool test(int a[], int b, int m){
	return a[m] > b;
}

int bs(int a[], int size, int b){
	int l = 0, r = size-1;

	while(l < r){
		int m = (l+r)/2;
		if(test(a,b,m)){
			r = m;
		}
		else{
			l = m+1;
		}
	}

	return r;
}

int main(){
	int n,m,i,t;
	cin>>n>>m;

	int a[n+1];
	int b[m];

	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		cin>>b[i];
	}

	sort(a, a+n);
	a[n] = 1012345678;

	for(i=0;i<m;i++){
		cout<<bs(a,n+1,b[i])<<" ";
	}
	cout<<endl;

	return 0;
}