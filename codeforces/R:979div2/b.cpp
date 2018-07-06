#include <bits/stdc++.h>
using namespace std;

#define LL long long int
LL maxDiffSize = 26*2;
LL n;
map<char,int> occurs[3];
string vals[3];
LL sameMax[3];

set<int> diff[3];


int getWinner(){
	int a = sameMax[0];
	int b = sameMax[1];
	int c = sameMax[2];

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
	int size = vals[0].size();

	for(int i=0; i<3; i++){
		LL max = 0;
		for(int j=0; j<size; j++){
			diff[i].insert(vals[i][j]);
			occurs[i][vals[i][j]]++;
			if(occurs[i][vals[i][j]] > max)
				max = occurs[i][vals[i][j]];
		}
		sameMax[i] = max;
	}

	for(int i=0; i<3; i++){
		sameMax[i] = sameMax[i] + n;
		if(sameMax[i] > size){
			if(sameMax[i] - size % 2 == 0)
				sameMax[i] = size;
			else
				sameMax[i] = size-1; 
		}
		if(sameMax[i] > size && diff[i].size() == maxDiffSize){
			int ret = sameMax[i] - size;
			ret = abs(ret - diff[i].size());
			if(ret % 2 == 0)
				sameMax[i] = size;
			else
				sameMax[i] = size-1;
		}

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
