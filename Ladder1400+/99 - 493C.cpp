#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,m;
vector<int> t1, t2;
LL bestDiffSoFar;

int test(int x){
	int pos1 = lower_bound(t1.begin(),t1.end(),x) - t1.begin();
	int pos2 = lower_bound(t2.begin(),t2.end(),x) - t2.begin();
	if(t1[pos1] == x) pos1++;
	if(t2[pos2] == x) pos2++;
	
	int pt1 = ((pos1)*2 ) + ( (n-pos1)*3  );
	int pt2 = ((pos2)*2 ) + ( (m-pos2)*3  );

	return (pt1 - pt2);
}

void printSol(int x){
	int pos1 = lower_bound(t1.begin(),t1.end(),x) - t1.begin();
	int pos2 = lower_bound(t2.begin(),t2.end(),x) - t2.begin();
	if(t1[pos1] == x) pos1++;
	if(t2[pos2] == x) pos2++;
	
	int pt1 = ((pos1)*2 ) + ( (n-pos1)*3  );
	int pt2 = ((pos2)*2 ) + ( (m-pos2)*3  );
	cout<<"Best: "<<x<<endl;
	cout<<pt1<<":"<<pt2<<endl;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		t1.push_back(a);
	}

	cin>>m;	
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		t2.push_back(a);
	}

	sort(t1.begin(),t1.end());
	sort(t2.begin(),t2.end());
	bestDiffSoFar = test(t1[n-1]+1);
	int done = t1[n-1]+1;

	int l = t1[0]-1, r = t1[n-1]+1;

	while(l < r){
		int m = (l+r)/2;
		if(test(m) >= bestDiffSoFar){
			done = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	printSol(done);
	return 0;
}
