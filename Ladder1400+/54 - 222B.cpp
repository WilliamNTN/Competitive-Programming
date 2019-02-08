
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1010;
int n,m,k;

int table[maxN][maxN];
int rows[maxN];
int cols[maxN];

int main(){
	
	scanf("%d%d%d",&n,&m,&k);	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&table[i][j]);
			cols[j] = j;
		}
		rows[i] = i;
	}
	while(k--){
		char c = getchar();
		int a,b;
		scanf("%c",&c);
		scanf("%d%d",&a,&b);
		a--;b--;
		if(c == 'c'){ //swap columns
			cols[a] += cols[b];
			cols[b] = cols[a] - cols[b];
			cols[a] -= cols[b];
		}else if(c == 'r'){ // swap rows
			rows[a] += rows[b];
			rows[b] = rows[a] - rows[b];
			rows[a] -= rows[b];
		}else{
			printf("%d\n",table[rows[a]][cols[b]]);
		}
	}
	return 0;
}
