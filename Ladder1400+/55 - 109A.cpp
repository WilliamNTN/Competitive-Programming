#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second

const int maxN = 1012345;

LL n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	
	int s7 = n/7,s4=0;

	for(s7; s7 > 0; s7--)
		if( (n - (s7*7)) % 4 == 0  ) break;	

	s4 = (n-(s7*7))/4;
	if((s7*7 + s4*4) != n) cout<<-1<<endl;
	else{
		for(int i = 0; i<s4;i++) cout<<4;
		for(int i = 0; i<s7; i++) cout<<7;
		cout<<endl;
	}


	return 0;
}
