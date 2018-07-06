#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL m,d;
LL a,b;


bool isMagic(LL a, LL d){
	string number;
	stringstream strstream;
	strstream << a;
	strstream >> number;

	int c = 0;
	for(LL i = 0; i<number.size(); i++){
		if(number[i] == d){
			c = 1;
			if(i%2 == 0)
				return false;
		}
	}

	if(c)
		return true;
	return false;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>m>>d;
	cin>>a>>b;

	a = a + (a%m);
	LL count = 0;

	while(a <= b){
		cout<<a<<endl;
		if(d == 0 || isMagic(a,d)){
			cout<<"entrou"<<endl;
			count++;
		}
		a+=m;
	}

	count = count / (pow(10,9)+7);
	cout<<count<<endl;

	return 0;
}
