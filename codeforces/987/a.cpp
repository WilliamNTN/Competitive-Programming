#include <bits/stdc++.h>
using namespace std;
#define LL long long int

map<string,int> used;
int n;
string colors[6] = {"purple","green","blue","orange","red","yellow"};
string names[6] = {"Power","Time","Space","Soul","Reality","Mind"};
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		used[a] = 1;
	}

	cout<<6-n<<endl;
	for(int i=0; i<6;i++){
		if(used[colors[i]] == 0)
			cout<<names[i]<<endl;
	}
	return 0;
}
