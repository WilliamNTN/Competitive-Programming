#include <bits/stdc++.h>
using namespace std;

#define key pair<int,int> //size, index

int n,k;
int vals[301234];

map<key,int> results; // size,index -> val

int sum(int a, int b){

	int sum = 0;
	for(int i=a; i<=b; i++)
		sum+= vals[i];

	return sum;
}

bool test(int size){

	for(int i = 0; i<=(n-size); i++){
		int s;
		if(results[make_pair(size-1,i)]){
			s = results[make_pair(size-1,i)] + vals[i+size-1];
		//	cout<<"caiu aqui"<<endl;			
		}
		else{
			s = sum(i,i+size-1) + k;
			//cout<<"Caiu onde faz tudo"<<endl;
		}

		results[make_pair(size,i)] = s;

		if(s >= size)
			return true;
	}

	return false;

}

int testIndex(int size){
	for(int i=0; i<=(n-size); i++){
		if( sum (i,i+size-1) + k >= size)
			return i;
	}
}
int bs(){
	// int l = k, r = n+1;

	// while(l < r){
	// 	int m = (l+r)/2;

	// 	if(test(m)){
	// 		l = m+1;
	// 	}
	// 	else
	// 		r = m;
	// }

	// return l -1;

	for(int i=k; i<=n; i++)
		if(!test(i))
			return i-1;

	return n;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i=0; i<n; i++){
		 cin>>vals[i];
	}
	

	int res = bs();
	cout<<res<<endl;
	int index = testIndex(res);

	for(int i=0; i<index; i++)
		cout<<vals[i]<<" ";

	for(int i = index; i<=(index+res-1); i++)
		cout<<1<<" ";

	for(int i = index+res; i<n; i++)
		cout<<vals[i]<<" ";

	cout<<endl;
	return 0;
}
