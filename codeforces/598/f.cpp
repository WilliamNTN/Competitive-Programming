#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;



double distance(double a, double b, double c, double d){
	return sqrt(pow((a-c),2) + pow((b-d),2));
}

//U x V = Ux*Vy-Uy*Vx
double crossProduct(double a1, double a2, double b1, double b2){
	return(a1*b2 - a2*b1);
}

int isInLine(pair<double,double> va, pair<double,double> vb, double c, double d){

	double kac, kab;

	// cout<<"Pontos: ("<<va.first<<","<<va.second<<")"<<endl;
	// cout<<"Pontos: ("<<vb.first<<","<<vb.second<<")"<<endl;
	// cout<<"Pontos: ("<<c<<","<<d<<")"<<endl;

	if(va.first == c && va.second == d)
		return 1;
	if(vb.first == c && vb.second == d)
		return 1;

	kac = crossProduct(va.first,va.second,vb.first,vb.second) * crossProduct(va.first,va.second,c,d);
	kab = (double)pow(crossProduct(va.first,va.second,vb.first,vb.second),2);

	
	// cout<<"KAC: "<<kac<<endl;
	// cout<<"KAB: "<<kab<<endl;

	if(kac >= 0 && kab > kac)
		return 1;
	return 0;
}
int isInNgon(vector<pair<double,double> > vecs, double a, double b){
	int i;

	for(i=0;i<(vecs.size()-1);i++){
		if(isInLine(vecs[i],vecs[i+1],a,b))
			return 1;
	}

	if(isInLine(vecs[vecs.size()-1],vecs[0],a,b))
		return 1;

	return 0;
}

int main(){
	int n,m,i;
	double a,b,c,d;
	cin>>n>>m;

	vector<pair<double,double> > vectors;

	for(i=0;i<n;i++){
		cin>>a>>b;
		vectors.push_back(make_pair(a,b));
	}

	cout<<fixed<<setprecision(20);
	for(i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		if(isInNgon(vectors,a,b) && isInNgon(vectors,c,d)){
			cout<<distance(a,b,c,d)<<endl;
		}
		else
			cout<<0<<endl;
	}


}