#include <bits/stdc++.h>
using namespace std;

typedef struct Item{
	string name;
	int w;

	Item(){}

	Item(string n, int ww){
		name = n;
		w = ww;
	}

}Item;

typedef struct Ret{
	vector<int> it;
	int w;

	Ret(){
		w = 0;
	}

}Ret;

Item itens[1010];
int students[110];

int trainingW,m,n;

Ret dp[1010][2020];
int dpaux[1010][2020];

string saux;
int waux;



Ret solve(int pos, Ret sofar, int desiredW, int totalW){
	if(pos > n) return sofar;
	if(desiredW <= 0) return sofar;

	if(dpaux[pos][desiredW] != -1)
		return dp[pos][desiredW];

	Ret one = solve(pos+1,sofar,desiredW,totalW); // nope

	sofar.it.push_back(pos);
	sofar.w += itens[pos].w;

	Ret two = solve(pos+1,sofar,desiredW - itens[pos].w,totalW); // yep

	dpaux[pos][desiredW] = 1;
	if(one.w < totalW && two.w < totalW){
		return dp[pos][desiredW] = sofar;
	}

	if(one.w < totalW) return dp[pos][desiredW] = two;
	if(two.w < totalW) return dp[pos][desiredW] = one;

	if(one.w == two.w) return dp[pos][desiredW] = one.it.size() <= two.it.size()? one:two;
	return dp[pos][desiredW] = one.w <= two.w? one: two;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>trainingW>>m;

	for(int i=1;i<=m;i++){
		cin>>saux>>waux;
		itens[i] = Item(saux,waux);
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>students[i];
		int desiredW = students[i]/2;
		if(students[i] % 2 != 0) desiredW++;
		desiredW -= trainingW;
		Ret r;
		memset(dpaux,-1,sizeof(dpaux));
		r = solve(1,r,desiredW,desiredW);
		
		if(r.w < desiredW) cout<<-1<<endl;
		else{
			cout<<r.it.size();
			for(int i=0; i<r.it.size(); i++)
				cout<<" "<<itens[r.it[i]].name;
			cout<<endl;
		}
	}

	return 0;
}