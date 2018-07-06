#include <bits/stdc++.h>
using namespace std;

#define LL long long int

const int N = 101234;

int n,q,cmm,c1;
double vals[N];
double tree[2*N];
double c2;

int buildTree(int node, int start, int end){
	if(start == end)
		return tree[node] = vals[start];

	int mid = (start+end)/2;

	return tree[node] = buildTree(2*node, start, mid) + buildTree(2*node + 1, mid+1, end);

}

double getSum(int node, int start, int end, int l, int r){
	if(r < start || l > end) return 0;

	if(l <= start && r >= end)
		return tree[node];

	int mid = (start+end)/2;
	return getSum(2*node,start, mid, l, r) + getSum(2*node + 1, mid+1,end,l,r);
}

void update(int node, int start, int end, int index, double change){

	if(start == end){
		tree[node] += change;
		return;
	}

	int mid = (start + end)/2;

	if(start <= index && index <= mid)
		 update(2*node,start, mid, index, change);
	else
		update(2*node+1,mid+1,end,index,change);

	tree[node] = tree[2*node] + tree[2*node+1];
	return ;

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i<=n; i++)cin>>vals[i];

	buildTree(1,1,n);

	cin>>q;
	
	while(q--){
		cin>>cmm>>c1>>c2;

		if(cmm == 1){
			double change = c2 - vals[c1];
			update(1,1,n,c1,change);
			vals[c1] = c2;
		}
		else{
			int len = (c2-c1+1);
			double sum = getSum(1,1,n,c1,c2);
			cout<<fixed<<setprecision(6)<<(double)(sum/(len*1.0))<<endl;
		}
	}

	return 0;
}
