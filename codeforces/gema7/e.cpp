#include <bits/stdc++.h>
using namespace std;

#define LL long long int



int fat(int n){
	int res = 1;
	while(n){
		res *=n--;
	}
	return res;
}

int comb(int n, int c){

	if(c == 0) return 0;
	return (fat(n)/ (fat(c) * fat(n-c)));
}

int getCombinations(int ndigits, int n){

	int nComb = comb(ndigits,n);

	int res = pow(9,ndigits-n);
	res *= nComb;

	return res;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	return 0;
}
