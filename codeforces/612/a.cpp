#include <bits/stdc++.h>
using namespace std;

int n,p,q;
string s;


void printSolution(int r){

	int total = n/r;
	cout<<total<<endl;

	int first = 0;

	while(first < n){
		cout<<s.substr(first,r)<<endl;
		first += r;
	}
}

int other(){

	int fn = n;
	int cp = 0, cq = 0;

	int d = 0;
	while(!d && fn > 0){
		fn -= p;
		cp++;
		if(((fn%q)==0)&& fn > 0)
			d = 1;
	}
	if(d == 1){
		cout<<cp+(fn/q)<<endl;
		for(int i=0; i<cp; i++){
			cout<<s.substr((p*i),p)<<endl;
		}
		int n = fn/q;
		for(int i=0; i<n; i++)
			cout<<s.substr(((p*cp)+(q*i)),q)<<endl;

		return 1;
	}

	d = 0;
	fn = n;
	while(!d && fn > 0){
		fn -= q;
		cq++;
		if(((fn%p)==0) && fn > 0){
			d = 1;
		}
	}

	if(d == 1){
		cout<<cq+(fn/p)<<endl;
		for(int i=0; i<cq; i++){
			cout<<s.substr((q*i),q)<<endl;
		}
		int n = fn/p;
		for(int i=0; i<n; i++)
			cout<<s.substr(((q*cq)+(p*i)),p)<<endl;

		return 1;
	}

	return 0;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>n>>p>>q>>s;
	
	if((n%p)==0){
		printSolution(p);
		return 0;	
	}
	if((n%q)==0){
		printSolution(q);
		return 0;
	}

	if((p+q)==n){
		cout<<2<<endl;
		cout<<s.substr(0,p)<<endl;
		cout<<s.substr(p,q)<<endl;
		return 0;
	}
	
	if(other())
		return 0;

	cout<<"-1"<<endl;
	return 0;
}
