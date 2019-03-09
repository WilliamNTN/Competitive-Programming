#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
string s,t;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	cin>>t;
	int tOnes = 0, tZeros = 0;
	int sOnes = 0, sZeros = 0;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1')
			sOnes++;
		else
			sZeros++;
	}
	for(int i = 0; i < t.size(); i++){
		if(t[i] == '1')
			tOnes++;
		else
			tZeros++;
	}

	if(sOnes < tOnes || sZeros < tZeros){
		cout<<s<<endl; return 0;
	}
	
	if(tOnes == 0){
		while(sZeros){
			cout<<0;
			sZeros--;
		}
		while(sOnes){
			cout<<1;
			sOnes--;
		}
		cout<<endl;
		return 0;
	}else if(tZeros == 0){
		while(sOnes){
			cout<<1;
			sOnes--;
		}
		while(sZeros){
			cout<<0;
			sZeros--;
		}
		cout<<endl;
		return 0;
	}

	int longestEqual = 0;
	for(int i = 0; i <= t.size()/2; i++){
		if(t.substr(0,i) == t.substr(t.size()-i)){
			longestEqual = i;
		}
	}
	cout<<t;
	sOnes -= tOnes;
	sZeros -= tZeros;

	string writeT = t.substr(longestEqual);
	tOnes = tZeros = 0;
	for(int i = 0; i < writeT.size(); i++)
		if(writeT[i] == '1')
			tOnes++;
		else
			tZeros++;

	while(sOnes >= tOnes && sZeros >= tZeros){
		cout<<writeT;
		sOnes -= tOnes;
		sZeros -= tZeros;
	}

	while(sOnes){
		cout<<1;
		sOnes--;
	}
	while(sZeros){
		cout<<0;
		sZeros--;
	}
	cout<<endl;
	return 0;
}
