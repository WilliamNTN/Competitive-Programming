#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 100100;
int n;
int a[maxN];
int b[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];

	for(int i = 0; i < n; i++)
		cin>>b[i];

	sort(a,a+n);
	sort(b,b+n);

	int pa = n-1;	
	int pb = n-1;
	LL sa = 0, sb = 0;
	while(pa >= 0 || pb >= 0){
		//A
		if(pb < 0){
			sa += a[pa--];
		}
		else{
			if(pa < 0 || a[pa] < b[pb])
				pb--;
			else if(pa >= 0)
				sa += a[pa--];
		}

		//B
		if(pa < 0)
			sb += b[pb--];
		else{
			if(pb < 0 || b[pb] < a[pa])
				pa--;
			else if(pb >= 0)
				sb += b[pb--];
		}
	}
	cout<<sa - sb<<endl;
	return 0;
}
	