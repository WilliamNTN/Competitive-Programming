#include <stdlib.h>




int bb(int *vector, int l, int r){

	while(l < r){
		int meio = (l+r)/2;

		if(teste(vector,meio)){
			r = meio;
		}
		else{
			l = meio+1;
		}
	}

	return r;	
}


int isInArray(char *array, int n, char c){
	int i;

	for(i=0;i<n;i++)
		if(arrau[i] == c)
			return 1;

	return 0;
}

int diffChars(char *array, int n){
	char aux[n];
	int auxP = 0,i;

	for(i=0;i<n;i++){
		if(!isInArray(aux, auxP, array[i])){
			aux[auxP++] = array[i];
		}
	}

	return auxP;
}
