

//Given an array of unique characters arr and a string str
// find the smallest substring of str containing
// all the characters in arr. Return "" if not possible


//Example
// arr = ['x','y','z']
// str = xyyzyzyx
// ans = zyx

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;


int test(char arr[maxN], int arrSize, string str, int window){ // Time = O(nlogn), Space = O(n)


	map<char,int> contain;
	int sofar = 0;

	for(int i = 0; i<window;i++){
		contain[str[i]]++;
		if(contain[str[i]] == 1) sofar++;
		if(sofar == arrSize) return i-window+1;
	}

	for(int i = window; i < str.size(); i++){
		contain[str[i-window]]--;
		if(contain[str[i-window]] == 0) sofar--;

		contain[str[i]]++;
		if(contain[str[i]] == 1) sofar++;

		if(sofar == arrSize) return i-window+1;
	}

	return -1;
}

string find(char arr[maxN], int arrSize, string str){

	int ans = -1;
	int lower = 1, upper = str.size();
	int middle = -1;
	while(lower <= upper){

		int middle = (lower+upper)/2;
		int check = test(arr,arrSize,str,middle);

		if(check >= 0){
			upper = middle-1;
			ans = check;
		}
		else{
			lower = middle+1;
		}
	}

	if(ans >= 0)
		return str.substr(ans,middle);
	else
		return "";

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin>>n;
	while(n){
		char arr[n];
		string str;
		for(int i = 0; i<n; i++) cin>>arr[i];

		cin>>str;
		cout<<find(arr,n,str)<<endl;

		cin>>n;
	}

	return 0;
}