#include <bits/stdc++.h>
using namespace std;



typedef struct{
	int value;
	int *occurrences;
	int *edges;
	int nEdges;
}Cell;


void print(Cell values[], int n){
	int i;

	for(i=0;i<n;i++){
		cout<<"Pos :"<<i<<endl;
		cout<<"Value :"<<values[i].value<<endl;
		cout<<"occurrences :"<<endl;
		for(int j=1; j<=n;j++){
			cout<<"Val "<<j<<" occur: "<<values[i].occurrences[j]<<endl;
		}
		cout<<endl;
	}

	cout<<endl<<endl;
}


int getBigger(int vec[], int n){
	int i,maior = -1;

	for(i=1; i<=n; i++){
		if(vec[i] > maior)
			maior = vec[i];
	}

	return maior;
}

int getMaiorSum(int vec[], int n, int maior){
	int soma = 0, i;

	for(i=1; i<=n; i++){
		if(vec[i] == maior)
			soma += i;
	}

	return soma;

}

int main(){

	int n,i;
	cin>>n;

	Cell values[n];
	for(i=0;i<n;i++){
		int v;
		cin>>v;
		Cell aux;
		aux.value = v;
		aux.nEdges = 0;
		aux.edges = (int*)malloc(sizeof(int)*(n));
		aux.occurrences = (int*)malloc(sizeof(int)*(n+1));
		values[i] = aux;
	}	


	for(i=0; i< (n-1);i++){
		int a,b;
		cin>>a>>b; a--;b--;
		values[a].edges[values[a].nEdges++] = b;
	}


	for(i=(n-1);i>=0;i--){
		values[i].occurrences[values[i].value]++;
		for(int j=0; j<values[i].nEdges;j++){
			int e = values[i].edges[j];
			for(int k = 1; k<=n;k++)
				values[i].occurrences[k] += values[e].occurrences[k];
		}
	}

	//print(values,n);

	int maior = getBigger(values[0].occurrences, n);
	cout<<getMaiorSum(values[0].occurrences,n,maior);

	for(i=1;i<n;i++){
		int maior = getBigger(values[i].occurrences, n);
		cout<<" "<<getMaiorSum(values[i].occurrences,n,maior);
	}
	cout<<endl;

	return 0;

}