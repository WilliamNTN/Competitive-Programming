

//Correct for small and large
//Time: O(P*N)
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int t;
int p,n;

typedef struct Trie{
	vector<Trie*> children; 

	char Data;
	bool isEnd;

	Trie(){
		children = vector<Trie*>(2,NULL);
		isEnd = false;
	}
	Trie(char d){
		Data = d;
		children = vector<Trie*>(2,NULL);
		isEnd = false;
	}

}Trie;

void insert(Trie *trie, string s){
	Trie *n = trie;
	for(int i = 0; i < s.size(); i++){
		int childrenPosition = s[i] == 'R'? 0 : 1;
		if(n->children[childrenPosition] == NULL){
			n->children[childrenPosition] = new Trie(s[i]);
		}
		n = n->children[childrenPosition];
	}
	n->isEnd = true;
}

bool find(Trie* trie,string s){
	Trie *n = trie;
	for(int i = 0; i < s.size(); i++){
		int childrenPosition = s[i] == 'R'? 0: 1;
		if(n->children[childrenPosition] == NULL) return false;
		n = n->children[childrenPosition];
		if(n->isEnd == true) return true;
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int i = 1; i <=t; i++){
		cin>>n>>p;
		LL removedPossibilities = 0;
		LL totalPossibilities = pow(2,n);
		Trie *trie = new Trie('*');
		vector<string> entries(p);
		for(int i = 0; i < p; i++){
			cin>>entries[i];
		}

		sort(entries.begin(),entries.end());
		for(int i = 0; i < entries.size(); i++){
			if(!find(trie,entries[i])){
				removedPossibilities += pow(2,n-entries[i].size());
			}
			insert(trie,entries[i]);
		}
		cout<<"Case #"<<i<<": "<<totalPossibilities - removedPossibilities<<endl;
	}
	return 0;
}