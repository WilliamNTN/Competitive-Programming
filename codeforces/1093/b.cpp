
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
int t;


bool isPalindrome(string s){
	int i = 0, j = s.size()-1;

	while(i < j){
		if(s[i] != s[j]) return false;
		i++; j--;
	}
	return true;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>t;
	while(t--){
		cin>>s;
		if(!isPalindrome(s)){
			cout<<s<<endl;
			continue;
		}
		int n = s.size();
		int diff = 0;
		set<char> st;
		for(int i = 0; i < n; i++){
			if(st.find(s[i]) == st.end())
				diff++;
			st.insert(s[i]);
		}
		if(diff == 1){
			cout<<-1<<endl;
		}
		else{
			for(int i = 1; i < n; i++)
				if(s[i] != s[0])
					swap(s[0],s[i]);
			cout<<s<<endl;
		}
	}
	return 0;
}
