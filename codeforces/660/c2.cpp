#include <bits/stdc++.h>
using namespace std;


int n,k;
int vals[301234];


int sum(int a, int b){

	int sum = 0;
	for(int i=a; i<=b; i++)
		sum+= vals[i];

	return sum;
}
int max(int a, int b){

	return a > b? a : b;
}
int solve(int pos, int nk, int ts){

	if(pos >= n)
		return ts;

	int t;
	if(vals[pos] == 0){
		int s1 = solve(pos+1,nk,0);
		int s2 = -1;
		if(nk > 0)
			s2 = solve(pos+1,nk-1,ts+1);
		
		t = max(s1,s2);
	}
	else{
		t = solve(pos+1,nk,ts+1);
	}

	return t;

}

int testIndex(int size){
	for(int i=0; i<=(n-size); i++){
		if( sum (i,i+size-1) + k >= size)
			return i;
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	int check = 0;
	for(int i=0;i<n;i++){
		 cin>>vals[i];
		 if(vals[i] == 1)
		 	check = 1;
	}

	int res = solve(0,k,0);
	if(check)
		res = 1;
	
	cout<<res<<endl;
	int index = testIndex(res);

	for(int i=0; i<index; i++)
		cout<<vals[i]<<" ";

	for(int i = index; i<=(index+res-1); i++)
		cout<<1<<" ";

	for(int i = index+res; i<n; i++)
		cout<<vals[i]<<" ";

	cout<<endl;

	return 0;
}
