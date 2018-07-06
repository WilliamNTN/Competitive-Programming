#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define LL long long int


LL n;
int piles[1012345];
int used[1012345][60];


int calcNS(){
	int ns = piles[0];
	for(int i=1; i<n; i++)
		ns = ns ^ piles[i];
	return ns;
}

int move(){
	int ns = calcNS();

	if(ns != 0){

		for(int i=0; i<n; i++){
			if((piles[i] ^ ns) < piles[i]){
				int removed = piles[i] - (piles[i] ^ ns);
				if(!used[i][removed]){
					used[i][removed] = 1;
					piles[i] = (piles[i]^ns);
					cout<<"Retirou "<<removed<<" da pilha "<<i<<endl;
					return 1;
				}
			}
		}
		for(int i=0; i<n; i++)
			cout<<piles[i]<<endl;
		return 0;
	}

	else{
		for(int i=0; i<n; i++){
			if(piles[i] > 0){
				for(int j = 1; j<=piles[i]; j++){
					if(!used[i][j]){
						used[i][j] = 1;
						piles[i] = piles[i] - j;
						cout<<"Retirou "<<j<<" da pilha" <<i<<endl;
						return 1;
					}
				}
			}
		}
		return 0;
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>piles[i];

	int turn = 1;    // 1 = SAM
	int done = 1;

	while(done){
		done = move();
		turn = !turn;
	}
	//turn wins
	if(turn){ // sam wins
		cout<<"NO"<<endl;
	}
	else
		cout<<"YES"<<endl;

	return 0;
}