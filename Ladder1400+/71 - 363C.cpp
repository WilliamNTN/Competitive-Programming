#include <bits/stdc++.h>
using namespace std;

string a;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a;

	cout<<a[0];
	int lastCount = 0, count = 1;
	for(int i=1;i<a.size();i++){
		if(a[i] == a[i-1])
			count++;
		else{
			lastCount = count;
			count = 1;
		}
		if(count >= 3){
			count--;
		}
		else if(count == 2 && lastCount == 2){
			count--;
		}
		else{
			cout<<a[i];
		}
	}
	cout<<endl;
	return 0;
}
