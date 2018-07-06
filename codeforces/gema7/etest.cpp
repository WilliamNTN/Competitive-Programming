#include <bits/stdc++.h>
using namespace std;

int lim, n, m;


int comb(int val){
	int s4 = 0;
	int s7 = 0;
	cout<<"Val: "<<val;
	while(val  > 0){
		int digit = val % 10;
		val = val/10;

		if(digit == 4)
			s4++;
		if(digit == 7)
			s7++;
	}
	cout<<", s4: "<<s4<<" s7: "<<s7<<endl;
	if(s4 == n || s7 == m)
		return 1;
	return 0;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>lim>>n>>m;

	int sum = 0;
	for(int i=1; i<= lim; i++){
		sum += comb(i);
	}

	cout<<sum<<endl;
	return 0;
}
