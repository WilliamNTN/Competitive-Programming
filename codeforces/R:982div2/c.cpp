#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[101234];
int u,v;


int getNGroups(int nFolhas){

	if(nFolhas == 1) return n/2;
	if(nFolhas > n/2) return -1;
	int ngrp= 0;
	if(nFolhas % 2 != 0) nFolhas--;
	while( (n % nFolhas != 0) ){
		nFolhas-=2;
	}

	if(nFolhas == 1) return n/2;
	return n/nFolhas;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	int countUsed = 0;

	for(int i=0;i<(n-1);i++){
		cin>>u>>v;
		graph[u].push_back(v);
		if(graph[u].size() == 1)
			countUsed++;
	}
	if(n % 2 != 0) cout<<-1<<endl;
	else{
		int res = getNGroups(n - countUsed);
		if(res <= 0) cout<<-1<<endl;
		else cout<<res-1<<endl;
	}
	return 0;
}
