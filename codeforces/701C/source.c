#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int inArray(char *arr, int n, char c){
	int i;

	for(i=0;i<n;i++)
		if(arr[i] == c)
			return 1;

	return 0;
}

int getDif(char *pok, int l, int r){
	char aux[112345];
	int count = 0,i;

	for(i=l;i<=r;i++)
		if(!inArray(aux,count,pok[i]))
			aux[count++] = pok[i];

	return count;

}
int works(char *pok, int n, int dif, int size){
	int hash[dif];

	hash[pok[i] % dif]++;
}

int bb(char *pok, int n){
	int dif = getDif(pok, 0, n-1);
	int l = dif, r = n;

	while(l < r){
		int m = (l+r)/2;
		if(works(pok,n,dif,m)){
			r = m;
		}
		else{
			l = m+1;
		}
	}

	return r;
}

int main(){
	int n,i;
	scanf("%d",&n);

	char *pok = (char*)malloc(sizeof(char)*n);
	scanf("%s",pok);


	printf("%d\n",bb(pok,n));
}