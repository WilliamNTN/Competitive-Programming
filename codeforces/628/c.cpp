#include <bits/stdc++.h>
using namespace std;


#define LL long long int

LL n,k;
string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	cin>>s;

	for(LL i=0; i<n; i++){
		
		int difZ = 'z' - s[i];
		int difA = s[i] - 'a';

		char charMaior = difA > difZ? 'a':'z';
		int maior = difA > difZ? difA: difZ;

		if(maior <= k){
			k -= abs(s[i] - charMaior);
			s[i] = charMaior;
		}
		else{
			if(charMaior == 'a')
				s[i] = s[i] - k;
			else
				s[i] = s[i] + k;
			k=0;
			break;
		}
	}
	if(k == 0)
		cout<<s<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
