#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define LL long long int


LL n,m;
int calcs[10123];
int mex(unordered_set<int> set){

 	for(int i=0; ; i++){
 		if(set.find(i) == set.end())
 			return i;
 	}
}

int grundy(int k){

	if(calcs[k] != -1)
		return calcs[k];
	cout<<"Grundy para "<<k<<endl;
	if(k <= m){
		calcs[k] = k;
		return calcs[k];
	}
 
    unordered_set<int> set;
 
    for (int i=1; i<=m; i++)
            set.insert(grundy(k - i));
 
 	calcs[k] = mex(set);
    return calcs[k];
}

int getBestMove(){

	for(int i=1; i<=m; i++)
		if(grundy(n-i)==0)
			return i;

	return -1;

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	for(int i=0; i<=n; i++)
		calcs[i] = -1;

	int g = grundy(n);

	if(g == 0)
		cout<<"O Loppa vai ficar pistola"<<endl<<0<<endl;
	else{
		int val = n % (m+1);
		cout<<"O Loppa vai mandar bem"<<endl<<val<<endl;
	}
	return 0;
}