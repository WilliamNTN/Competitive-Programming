#include <bits/stdc++.h>
using namespace std;

int n;
string vals[3];
map<char,int> occur[3];
int maxOccur[3];


int getWinner(){
	int a = maxOccur[0];
	int b = maxOccur[1];
	int c = maxOccur[2];

	if(a > b && a > c){
		return 0;
	}
	if(b > a && b > c)
		return 1;
	if(c > a && c > b)
		return 2;

	return -1;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	cin>>vals[0]>>vals[1]>>vals[2];
	memset(maxOccur,0,sizeof(maxOccur));
	int size = vals[0].size();

	for(int i=0;i<3;i++){
		int thisMax = 0;
		for(int j=0; j<size;j++){
			occur[i][vals[i][j]]++;
			if(occur[i][vals[i][j]] > thisMax)
				thisMax = occur[i][vals[i][j]];
		}
		maxOccur[i] = thisMax;
	}

	for(int i=0; i<3; i++){
		if(maxOccur[i] == size && n == 1)
			maxOccur[i] = size-1;
		else
			maxOccur[i] = (maxOccur[i] + n);
		if(maxOccur[i] > size)
			maxOccur[i] = size;

	}

	int winner = getWinner();

	if(winner == -1)
		cout<<"Draw"<<endl;
	else if(winner == 0)
		cout<<"Kuro"<<endl;
	else if(winner == 1)
		cout<<"Shiro"<<endl;
	else cout<<"Katie"<<endl;


	return 0;
}
