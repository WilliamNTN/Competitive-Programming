#include <bits/stdc++.h>

using namespace std;

int main(){
	double freq[26] = {0.0};
	string entrada;

	cin>>entrada;

	for(int i = 0; i<entrada.size(); i++){
		freq[entrada[i] - 'a']++;
	}

	for(int i=0; i<26; i++){
		if((int)freq[i] % 2 != 0){
			for(int j=25; j>i; j--){
				if(((int)freq[j] % 2) != 0){
					freq[j]--; freq[i]++;
					j = 0;
				}
			}
		}
	}
	
	int meio = -1;
	for(int i = 0; i<26; i++){
		if((int)freq[i]%2 != 0){
			meio = i;
			freq[i]--;
		}
		int count = ceil(freq[i]/2.0);
		for(int j=0; j<count; j++)
			cout<<(char)('a'+i);
		freq[i] -= count;
	}

	if(meio >= 0)
		cout<<(char)('a'+meio);

	for(int j=25; j>=0; j--){
		for(int i =0; i< freq[j]; i++)
			cout<<(char)('a'+j);
	}

	cout<<endl;

	return 0;

}