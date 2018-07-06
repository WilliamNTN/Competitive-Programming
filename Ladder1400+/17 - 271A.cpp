#include <bits/stdc++.h>
using namespace std;
#define LL long long int

bool isValid(int n){

	set<int> used;

	while(n > 0){
		int digit = n%10;
		if(used.count(digit) > 0) return false;
		used.insert(digit);
		n = n/10;
	}

	return true;
}
int year;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>year; year++;

	while(!isValid(year)) year++;

	cout<<year<<endl;

	return 0;
}
