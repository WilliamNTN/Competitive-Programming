#include <bits/stdc++.h>
using namespace std;


string s;

int nZerosFront(string a){	// size
	int nZeros = 0;
	for(int i=0; i<(a.size()-1); i++){
		if(a[i] == '0'){
			nZeros++;
		}
		else{
			break;
		}
	}
	return nZeros;
}

int nUnBack(int posP){ // size
	int ret = 0;

	for(int i = s.size()-1; i>posP; i--)
		if(s[i] == '0' || s[i] == '.')
			ret++;
		else
			break;

	return ret;
}

int getPPosition(){ // size
	int posP;
	for(posP = 0; s[posP] != '.' && posP < s.size(); posP++);

	return posP;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	if(s.size() == 1){	// se estiver pronto
		cout<<s<<endl;
		return 0;
	}
	int posP = getPPosition();
	if(posP == s.size())
		s = s + '.';

	s = s.substr(nZerosFront(s)); // retira zeros fa frente.
								// Possíveis formatos: .000, .xxx, .
	
	if(s.size() == 1){
		cout<<0<<endl;
		return 0;
	}

	posP = getPPosition();

	s = s.substr(0,s.size()-nUnBack(posP)); // retira 0 de trás, até o ponto
	if(s.size() == 1){
		cout<<0<<endl;
		return 0;
	}

	int count = 0;

	for(int i = posP; i>1; i--){ // coloca ponto na segunda posicao
		swap(s[i],s[i-1]);
		count++;
	}
	posP = getPPosition();

	string aux = s.substr(0,posP+1);
	string aux2 = s.substr(posP+1);
		int aux2size = aux2.size();

	aux2 = aux2.substr(nZerosFront(aux2));
	s = aux + aux2;
	count -= aux2size - aux2.size()+1;
	while(posP == 0){
		count--;
		swap(s[0],s[1]);
		s = s.substr(nZerosFront(s));
		posP = getPPosition();
	}


	s = s.substr(0,s.size() - nUnBack(posP-1));
	
	if(count == 0)
		cout<<s<<endl;
	else
		cout<<s<<"E"<<count<<endl;
	return 0;
}