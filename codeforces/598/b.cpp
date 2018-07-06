#include <iostream>
#include <string>

using namespace std;


int main(){
	string entrada;
	cin >> entrada;
	int size = entrada.size();
	int valores[size] = {0};
	int mQueries, l, r, k,count=0,i,j,kk;

	cin>>mQueries;
	string resposta;



	while(count < mQueries){
		count++;
		cin>>l>>r>>k;
		l--;r--;
		int moveSize = (r-l);
		k = k%((moveSize+1));

		resposta = entrada;
		for(i=0;i<=moveSize;i++){
			resposta[((i+k)%(moveSize+1))+l] = entrada[i+l];
		}

		entrada = resposta;
	}

	cout<<resposta<<endl;


	

	return 0;
}	