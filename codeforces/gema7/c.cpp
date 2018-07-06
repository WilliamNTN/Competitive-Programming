#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define key pair<pair<int,int>,int>

int n1,n2,n3;

map<key,LL> res;

key makeKey(int a, int b, int c){

	return make_pair(make_pair(a,b),c);
}

LL solve(int a1, int a2, int a3){
	if((!a1)||(!a2)||(!a3))
		return 1;

	if(res[makeKey(a1,a2,a3)])
		return res[makeKey(a1,a2,a3)];
	LL sum = 0;
	if(a2 <= a1){
 		LL s = solve(a1-a2,a2,a3);
 		res[makeKey(a1-a2,a2,a3)] = s;
 		sum += s;
	}

	if(a3 <= a1){
 		LL s = solve(a1-a3,a2,a3);
 		res[makeKey(a1-a3,a2,a3)] = s;
 		sum += s;
	}

	if(a1 <= a2){
 		LL s = solve(a1,a2-a1,a3);
 		res[makeKey(a1,a2-a1,a3)] = s;
 		sum += s;
	}

	if(a3 <= a2){
 		LL s = solve(a1,a2-a3,a3);
 		res[makeKey(a1,a2-a3,a3)] = s;
 		sum += s;
	}

	if(a1 <= a3){
 		LL s = solve(a1,a2,a3-a1);
 		res[makeKey(a1,a2,a3-a1)] = s;
 		sum += s;
	}

	if(a2 <= a3){
 		LL s = solve(a1,a2,a3-a2);
 		res[makeKey(a1,a2,a3-a2)] = s;
 		sum += s;
	}

	return sum % ((LL) (pow(10,9)+7)); 
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n1>>n2>>n3;
	LL ret = solve(n1,n2,n3) % ((LL)pow(10,9)+7);
	cout<<ret<<endl;

	return 0;
}
