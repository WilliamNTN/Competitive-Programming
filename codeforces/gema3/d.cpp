#include <bits/stdc++.h>
using namespace std;

int n,m;
char mat[1012][1012];

#define fi first
#define se second

int haveMonsterColumn(int a, int b){
	int monster = 0, wall = 0;

	for(int i = 0; i<a;i++){
		if(mat[i][b] == 'D')
			monster = 1;
		if(mat[i][b] == '#')
			monster = 0;
	}

	if(!monster){
		for(int i = a+1; i<n; i++){
			if(mat[i][b] == '#')
				return 0;
			if(mat[i][b] == 'U')
				return 1;
		}
	}

	return monster;
}	

int haveMonsterLine(int a, int b){
	int monster = 0, wall = 0;

	for(int i = 0; i<b; i++){
		if(mat[a][i] == 'R')
			monster = 1;
		if(mat[a][i] == '#')
			monster = 0;
	}

	if(!monster){
		for(int i = b+1; i<m; i++){
			if(mat[a][i] == '#')
				return 0;
			if(mat[a][i] == 'L')
				return 1;
		}
	}

	return monster;
}
int main(){
	
	cin>>n>>m;

	vector<pair<int,int> > pontos;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char a;
			cin>>a;
			mat[i][j] = a;
			if(a == '.')
				pontos.push_back(make_pair(i,j));
		}
	}

	int count = 0;

	for(int i = 0; i<pontos.size(); i++){

		int monsterC = haveMonsterColumn(pontos[i].fi,pontos[i].se);
		int monsterL = haveMonsterLine(pontos[i].fi,pontos[i].se);

		if(!monsterC && !monsterL){
			count++;
			if(count == 2)
				break;
		}
	}
	
			

	if(count == 0)
		cout<<"NO SOLUTION"<<endl;
	if(count == 1)
		cout<<"ONLY ONE SOLUTION"<<endl;
	if(count >= 2)
		cout<<"MULTIPLE SOLUTIONS"<<endl;

	return 0;
}