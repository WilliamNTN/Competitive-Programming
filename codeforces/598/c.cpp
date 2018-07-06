#include <bits/stdc++.h>

#define fi first
#define se second

#define double long double
using namespace std;


typedef struct {
	double theta;
	int pos;
}Entry;

double getTheta(double x, double y){

	return atan2(y,x);
}


double getNorm(double a, double b){

	return (sqrt( pow(a,2) + pow(b,2) ));

}

bool compare(const Entry &a, const Entry &b){
	return fabs(a.theta) < fabs(b.theta);
}

int main(){
	int n,i,j;
	cin>>n;

	vector<pair<int, int> > positions;
	for(i=0;i<n;i++){
		cin>>a>>b;
		positions.push_back(a,b);
	}

	
	return 0;
}