//Implement an algorithm ti determine if a string has all unique characters
// What if you cannot use aditional data structures?

#include <iostream> 	// io
#include <string>		// string
#include <set>			// set
#include <algorithm>	// sort
using namespace std;



// Time: O(nlog(n)), limited by sorting
// Space: O(1). Do not uses any other memory but the string. True if in-place sorting
bool isUniqueSorting(string s){ 
	sort(s.begin(),s.end());

	for(int i=1;i<s.size(); i++)
		if(s[i] == s[i-1])
			return false;
	return true;
}

// Time: O(n), but uses aditional data structure
// Space: O(n), each char is stored once in the set
bool isUniqueHash(string s){	
	set<char> set;
	for(int i=0;i<s.size();i++){
		if(set.count(s[i]) > 0)
			return false;
		set.insert(s[i]);
	}

	return true;
}

int main(){

	string s;

	cin>>s;

	cout<<isUniqueHash(s)<<endl;
}