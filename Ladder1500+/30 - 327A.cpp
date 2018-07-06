#include <bits/stdc++.h>
using namespace std;
#define pair pair<int,int>
#define fi first			// size
#define se second			// diff
int n;
int numbers[100];
int mat[100][100];

int sum(){
	int s = 0;

	for(int i=0;i<n;i++)
		s += numbers[i];
	return s;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>numbers[i];
		mat[i][i] = numbers[i];
	}

	
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			if(i!=j){
				mat[i][j] = mat[i][j-1] + numbers[j];
			}
		}
	}
	return 0;
}
