#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef std::map<char, int> Hash;

Hash hash;


int isInVector(vector<char> vec, char c){
	int i;

	for(i=0;i<vec.size();i++)
		if(vec[i] == c)
			return 1;

	return 0;
}


int countPokes(string pokes, int n){
	vector<char> aux;
	int i;

	for(i=0;i<n;i++){
		if(!isInVector(aux,pokes[i])){
			aux.push_back(pokes[i]);
			hash[pokes[i]] = 0;
		}
	}


	return aux.size();
}

int hasZero(){
	for(Hash::iterator it = hash.begin(); it != hash.end(); it++){
		if(it->second == 0){
			return 1;
		}
	}

	return 0;
}
int test(string pokes, int npokes, int size){
	int l = 0, r = size-1;
	int i, zeroFound;

	for(i=l; i<=r; i++){
		hash[pokes[i]]++;
	}

	zeroFound = hasZero(); 

	if(!zeroFound) // essa posição da janela ja deu certo
		return 1;

	l++; r++;
	while(r < pokes.size()){
		hash[pokes[l-1]]--;		
		hash[pokes[r]]++;

		zeroFound = hasZero();

		if(!zeroFound)
			return 1;

		l++;r++;
	}


	return 0;
	
}
void zeraHash(){
	for(Hash::iterator it = hash.begin(); it != hash.end(); it++)
		it->second = 0;
}
int solve(string pokes, int n, int npokes){
	int l = npokes, r = n;

	while(l < r){
		int m = (l+r)/2;
		zeraHash();
		if(test(pokes,npokes,m)){
			
			r = m;
		}
		else{
			
			l = m+1;
		}
	}

	return r;
}

int main(){
	int n, npokes,i;
	string pokes;

	cin >> n;
	cin >> pokes;


	npokes = countPokes(pokes, n);
	cout << solve(pokes, n, npokes) << endl;
	return 0;
}
