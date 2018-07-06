#include <bits/stdc++.h>
using namespace std;


bool isVog(char c){
	return ( (c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u'));
}

string entrada;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>entrada;
	int vog = 0;
	for(int i=0;i<entrada.size();i++){
		if(!isVog(entrada[i])){
			cout<<entrada[i];
			vog = 0;
		}
		else{
			if(!vog){
				cout<<entrada[i];
				vog = 1;
			}
		}
	}
	cout<<endl;
	return 0;
}
