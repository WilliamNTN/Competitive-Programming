#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,p;
string s;
map<int,int> todo;

int walk(int tp, int mov){
	tp += mov;
	if(mov < 0) tp = (n-1);
	if(mov > 25) tp = 0;

	return tp;
}

int getDiff(char src, char dst){
	int mov = ((dst - src));
	if(abs(mov) > 13){
		if(mov > 0) mov = 26 - mov;
		else mov = mov + 26;
	}

	return abs(mov);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>p;
	cin>>s;
	p--;

	int mean = (n/2)-1;
	if(p > mean)
		p = ((n-1)-p);

	int l = p, r = p;
	for(int i = 0; i<= mean; i++){
		todo[i] = getDiff(s[i],s[n-1-i]);
		if(todo[i] > 0 && i < l) l = i;
		if(todo[i] > 0 && i > r) r = i;
	}
	int count = 0;

	if( abs(p-l) < abs(p-r)  ){ // left first
		
		count += todo[p]; todo[p] = 0;
		int pos = p-1;

		for(pos; pos >=l; pos--){
			count += todo[pos]+1;
			todo[pos] = 0;
		}
		pos +=2;

		for(pos; pos <= r; pos++){
			count += todo[pos]+1;
			todo[pos] = 0;

		}

	}
	else{
		count += todo[p];
		todo[p] = 0;
		int pos = p+1;

		for(pos; pos <= r; pos++){
			count += todo[pos]+1;
			todo[pos] = 0;
		}
		pos -=2;

		for(pos; pos >=l; pos--){
			count += todo[pos]+1;
			todo[pos] = 0;
		}
	}

	cout<<count<<endl;
	return 0;
}
