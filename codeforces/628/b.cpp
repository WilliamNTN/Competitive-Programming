#include <bits/stdc++.h>
using namespace std;

#define LL long long int

string s;
LL size;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	char* endptr = NULL;
	
	cin>>s;


	size = s.size();

	LL count = 0;

	for(LL i = 0; i<size; i++){
		if( (s[i] - '0')%4 == 0)
			count++;
		if(i > 0){
			int dez = s[i-1] - '0';
			if( ((dez*10)+(s[i]-'0'))%4 == 0)
				count+=i;
		}
	}
	cout<<count<<endl;

	return 0;
}
