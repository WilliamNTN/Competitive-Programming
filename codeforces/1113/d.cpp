#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
string s;


bool isPalindrome(string a){

	int i = 0, j = a.size()-1;
	while(i < j){
		if(a[i] != a[j]) return false;
		i++; j--;
	}
	return true;
}

int solve(string a){
	string first = s.substr(0,s.size()/2);
	string second = s.substr(0,s.size()/2 + 1);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	if(s.size()%2 != 0){
		string first = s.substr(0,s.size()/2);
		string second = s.substr(s.size()/2+1);

		if(second+first == s)
			cout<<"Impossible"<<endl;
		else
			cout<<2<<endl;
		return 0;
	}
	else{
		string first = s.substr(0,s.size()/2);
		string second = s.substr(s.size()/2);

		if(second + first != s){
			cout<<1<<endl;
			return 0;
		}

		for(int i = 1; i <=s.size()/2; i++){
			string a = s.substr(0,i);
			string b = s.substr(i);
			if(b + a != s && isPalindrome(b+a)){
				cout<<1<<endl;
				return 0;
			}
		}

	}
	cout<<"Impossible"<<endl;
	return 0;
}
