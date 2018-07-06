#include <bits/stdc++.h>
using namespace std;


typedef struct Seat{
	int pos;
	int w, occ;

	Seat(){}
	Seat(int p, int _w, int o){
		pos = p;
		w = _w;
		occ = o;
	}
}Seat;

bool sortBySize(const Seat &a, const Seat &b){
	return a.w < b.w;
}

int n;
Seat bus[400400];
string s;
#define LL long long int
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; i++){
		int wi; cin>>wi;
		bus[i] = Seat(i+1,wi,0);
	}

	cin>>s;

	sort(bus,bus+n,sortBySize);
	
	int nextEPosition[400400];
	memset(nextEPosition,0,sizeof(nextEPosition));

	int iP = 0, eP = -1;

	for(int i=0; i<s.size(); i++){
		if(s[i] == '0'){
			bus[iP].occ = 1;
			cout<<bus[iP].pos<<" ";
			iP++;
			nextEPosition[++eP] = iP-1;
		}
		else{
			bus[nextEPosition[eP]].occ = 1;
			cout<<bus[nextEPosition[eP]].pos<<" ";
			--eP;
		}
	}

	cout<<endl;
	return 0;
}
