#include <bits/stdc++.h>
using namespace std;

#define LL long long int

string a,b;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char *endptr = NULL;

	cin>>a>>b;

	if(a.size() > b.size()){
		int diff = a.size() - b.size();
		string ad(diff,'0');
		b.insert(0,ad);
	}
	else if(a.size() < b.size()){
		int diff = b.size() - a.size();
		string ad(diff,'0');
		a.insert(0,ad);
	}


	if(a < b)
		cout<<"<"<<endl;
	else if(a > b)
		cout<<">"<<endl;
	else 
		cout<<"="<<endl;

	return 0;
}
