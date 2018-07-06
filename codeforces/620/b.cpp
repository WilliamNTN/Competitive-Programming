#include <bits/stdc++.h>
using namespace std;
#define LL long int


int values[10] = {6,2,5,5,4,5,6,3,7,6};

LL a,b;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b;
	LL total = 0;

	for(LL i=a; i<=b; i++){
		LL aux = i;
		while(aux > 0){
			LL lastDigit = (aux%10);
			total += values[lastDigit];
			aux = aux/10;
		}
	}

	cout<<total<<endl;

	return 0;
}
