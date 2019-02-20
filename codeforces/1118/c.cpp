#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 440;
int n;
int vals[maxN];
map<int,int> hashMap;
int mat[maxN][maxN];

int solveEven(){
	map<int,int>::iterator it;
	for(it = hashMap.begin(); it != hashMap.end(); it++){
		if(it->second%4 != 0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	int i = 0;
	int j = 0;
	for(it = hashMap.begin(); j < n/2 && it != hashMap.end();){
		if(it->ss == 0){
			it++;continue;
		}
		mat[i][j] = mat[i][n-1-j] = mat[n-1-i][j] = mat[n-1-i][n-1-j] = it->ff;
		(it)->ss -= 4;
		i++;
		if(i == n/2){
			i = 0;
			j++;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}


int solveOdd(){
	int total =max(n*n-n-n-1,0);
	map<int,int>::iterator it;
	for(it = hashMap.begin(); total > 0 && it != hashMap.end(); it++){
		if(it->ss >= 4){
			total -= min(total,(it->ss/4)*4);
		}
	}
	if(total != 0){
		cout<<"NO"<<endl;
		return 0;
	}
	bool flag = false;
	for(it = hashMap.begin(); it != hashMap.end(); it++){
		if(it->ss%2 != 0 && flag){
			cout<<"NO"<<endl;
			return 0;
		}
		if(it->ss%2 != 0)
			flag = true;
	}
	cout<<"YES"<<endl;
	int i = 0, j = 0;
	for(it = hashMap.begin(); j < n/2 && it != hashMap.end();){// for dos cantos
		if(it->ss < 4){
			it++;
			continue;
		}
		mat[i][j] = mat[i][n-1-j] = mat[n-1-i][j] = mat[n-1-i][n-1-j] = it->ff;
		(it)->ss -= 4;
		i++;
		if(i == n/2){
			i = 0;
			j++;
		}
	}
	i = 0;
	j = n/2;

	for(it = hashMap.begin(); i < n/2;i++){//meios
		if(it->ss < 2){
			it++;
			i--;
			continue;
		}
		if(it->ss >= 2){
			mat[i][j] = mat[n-1-i][j] = it->ff;
			it->ss -= 2;
		}
	}
	i = n/2;
	j = 0;
	for(it = hashMap.begin(); j < n/2;j++){//meios
		if(it->ss < 2){
			it++;
			j--;
			continue;
		}
		if(it->ss >= 2){
			mat[i][j] = mat[i][n-1-j] = it->ff;
			it->ss -= 2;
		}
	}

	for(it = hashMap.begin(); it != hashMap.end(); it++){
		if(it->ss != 0){
			mat[n/2][n/2] = it->ff;
			break;
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i  = 0; i < n*n; i++){
		cin>>vals[i];
		hashMap[vals[i]]++;
	}
	if(n%2 == 0)
		return solveEven();
	return solveOdd();
}
