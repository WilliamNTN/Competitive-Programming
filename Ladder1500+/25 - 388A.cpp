#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n;
int boxes[101];


int min(int a, int b){
	return a < b? a:b;

}

int test(int m){
	int capacity[m];

	for(int i=0;i<m;i++)
		capacity[i] = 101;

	int boxid = 0;
	int nopeCount = 0;
	for(int i=0; i<n; i++){
		if(capacity[boxid] == -1){
			capacity[boxid] = boxes[i];
			boxid = (boxid+1)%m;
			nopeCount = 0;
		}
		else if(capacity[boxid] > 0){
			capacity[boxid] = min(capacity[boxid]-1,boxes[i]);
			boxid  = (boxid+1)%m;
			nopeCount = 0;
		}else{
			boxid = (boxid+1)%m;
			nopeCount++;
			if(nopeCount == m)
				return 0;
			i--;
		}
	
	}

	return 1;
}

int bs(){
	int l = 1;
	int r = n;

	while(l<r){
		int m = (l+r)/2;
		if(test(m)){
			r = m;
		}
		else
			l = m+1;
	}

	return r;
}

bool sortD(const int &a, const int &b){
	return a > b;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>boxes[i];
	}
	sort(boxes,boxes+n,sortD);
	cout<<bs()<<endl;
	return 0;
}
