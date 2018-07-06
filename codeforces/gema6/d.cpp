#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,k;
LL vals[101234];
LL final[101234];
LL moves[10124];
LL total[1012345];

LL getDiff(LL src, LL dst){
	LL mov = (dst - src);

	if(abs(mov) > 5){
		if(mov > 0) mov = mov - 10;
		else mov = mov + 10;
	}

	return mov;
}
void rotate(LL i, LL mov){
	vals[i] = (vals[i] + mov)%10;

	if(vals[i] < 0)
		vals[i] = 10 + vals[i];
}	
void print(){
	cout<<"MOVES"<<endl;
	for(LL i=k; i<(n+k); i++){
		cout<<moves[i]<<" ";
	}

	cout<<endl<<"TOTAL"<<endl;
	for(LL i=k;i<(n+k);i++)
		cout<<total[i]<<" ";
	cout<<endl;
}
//-----------------------------------------
// ini | 1 | 1 | 2 | 2 | 4 | 6 |		// inicial
// fin | 2 | 3 | 3 | 4 | 5 | 4 |		// final
// mov | 1 | 1 | -1| 2 | 0 | 0 |			// mov feito quando inicial aqui
// to  | 1 | 2 | 1 | 3 | 3 | 3 |				// moves totais feitos nessa posicao
//------------------------------------------

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(LL i=0; i<=k; i++){

		total[i] = 0;
	}
	
	for(LL i=0;i<n;i++)						
		cin>>vals[i];

	for(LL i=0;i<n;i++){					
		cin>>final[i];
	}
	
	LL movT = 0;
	for(LL i=0; i<n; i++){
		vals[i] = vals[i] + total[i-1+k] - total[i];
		LL mov = getDiff(vals[i],final[i]);
		movT += abs(mov);
		moves[i] = mov;
		total[i+k] = total[i-1+k] + mov;
	}

	if(k == 1)
		cout<<movT<<endl;
	else{
		for(LL i = n-k+1; i < n; i++)
			if(moves[i] != 0){
				cout<<-1<<endl;
				return 0;
			}

		cout<<movT<<endl;
	}	

	

	return 0;
}
