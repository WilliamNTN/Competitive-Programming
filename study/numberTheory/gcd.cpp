#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL a,b;


//GCD de 2 numeros não muda se o menor for subtraido do maior
LL myGCD(LL a, LL b){
	if(!a || !b) return 0;

	if(a == b) return a;

	if(a > b) return myGCD(a-b,b);
	return myGCD(a,b-a);
}

LL mySecondGCD(LL a, LL b){
	if(!a && !b) return 0;

	if(a == b) return a;

	while(a != b){
		if(a > b)
			a = a-b;
		else
			b = b-a;
	}
	mySecondGCD(a,b);
}

LL anotherGCD(LL a, LL b){

	if(a == 0) return b;

	return anotherGCD(b%a,a);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b;
	cout<<anotherGCD(a,b)<<endl;
	return 0;
}
