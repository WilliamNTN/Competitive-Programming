
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second

const int maxN = 51;

int t;



bool isIn(map<char,int> inB[maxN][maxN], int pos1, int pos2, vector<char> letters){
	int check = 1;
	map<char,int> cop = inB[pos1][pos2];

	for(int i = 0; i < letters.size(); i++){
		if(cop[letters[i]] == 0) return false;
		cop[letters[i]]--;
	}

	return true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int count = 1;
	cin>>t;
	while(t--){
		int L;
		string A,B;
		cin>>L>>A>>B;
		map<char,int> inB[maxN][maxN];
		for(int window = 0; window < L; window++){
			for(int start = 0; (start+window)<L; start++){
				for(int k = start; k <=(start+window); k++){
					inB[window][start][B[k]]++;
				}
			}
		}
		LL ans = 0;
		for(int window = 0; window < L; window++){
			for(int start = 0; start+window < L; start++){
				vector<char> present;
				for(int k = start; k <= start+window; k++){
					present.push_back(A[k]);
				}

				for(int pos = 0; pos+window<L;pos++){
					if(isIn(inB,window,pos,present)){
						ans++;
						pos = L;
					}
				}
			}
		}

		cout<<"Case #"<<count++<<": "<<ans<<endl;
	}


	return 0;
}
