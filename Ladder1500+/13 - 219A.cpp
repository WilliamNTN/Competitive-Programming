#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n;
string s;
LL freq[26];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	
	for(LL i=0; i<s.size(); i++){
		freq[s[i] - 'a']++;
	}

	for(LL i=0; i<26; i++)
		if(!(freq[i] == 0 || freq[i]%n == 0)){
			cout<<-1<<endl;
			return 0;
		}

	for(LL k = 0; k<n;k++){
		for(LL i=0; i<26; i++){
			if(freq[i]!=0){
				for(LL j = 0; j<(freq[i]/n); j++)
					cout<<(char)('a'+i);
			}
		}
	}

	cout<<endl;
	return 0;
}
