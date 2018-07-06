#include <bits/stdc++.h>
using namespace std;

#define pair pair<int,int>
#define fi first
#define se second

bool byFirst(const pair &a, const pair &b){
	return a.fi < b.fi;
}

int n;
pair f[100];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++){
		pair aux;
		cin>>aux.fi;
		aux.se = i;
		f[i] = aux;
	}

	sort(f,f+n,byFirst);

	for(int i=0;i<n;i++)
		cout<<f[i].se+1<<" ";
	cout<<endl;

	return 0;
}
