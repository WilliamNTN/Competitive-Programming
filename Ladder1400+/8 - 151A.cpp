#include <bits/stdc++.h>
using namespace std;

//time 7:37

int n,k,l,c,d,p,nl,np;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k>>l>>c>>d>>p>>nl>>np;


	int totalMl = k * l;
	int totalSlices = c * d;
	int totalSalt = p;

	int toasts = min(totalMl/(n*nl), totalSlices/n);
	toasts = min(toasts, totalSalt/(n*np));

	cout<<toasts<<endl;

	return 0;
}
