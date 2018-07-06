#include <bits/stdc++.h>
using namespace std;

#define LL long long int

double a,b,c,d;

double max(double a, double b){
	return a>b?a:b;
}

double getPoints(double cost, double time){

	return max(((3.0*cost)/10.0),(cost - (cost/250.0)*time));
}
int main(){

	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b>>c>>d;

	double M = getPoints(a,c);
	double V = getPoints(b,d);

	if(M == V)
		cout<<"Tie"<<endl;
	
	else if(M > V)
		cout<<"Misha"<<endl;
	else
		cout<<"Vasya"<<endl;
	return 0;
}
