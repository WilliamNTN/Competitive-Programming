#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,h,ant,aux,total=0;

	cin>>n>>h;
	
	cin>>ant;
	for(int i=1;i<n;i++){
		cin>>aux;
		total += abs(ant-aux);
		ant = aux;
	}

	cout<<total*4<<endl;
	return 0;


}