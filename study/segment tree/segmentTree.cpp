#include <bits/stdc++.h>
using namespace std;

const int maxN = 101234;

int tree[2*maxN];
int vals[maxN];
int n;

int buildTree(int node, int start, int end){
	if(start == end)
		return tree[node] = vals[start];

	int mid = (start+end)/2;

	return tree[node] = buildTree(2*node, start, mid) + buildTree(2*node + 1, mid+1, end);

}

int getSum(int node, int start, int end, int l, int r){
	if(r < start || l > end) return 0;

	if(l <= start && r >= end)
		return tree[node];

	int mid = (start+end)/2;
	return getSum(2*node,start, mid, l, r) + getSum(2*node + 1, mid+1,end,l,r);
}

void update(int node, int start, int end, int index, int change){

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
	for(int i=1; i<=n; i++)
		cin>>vals[i];

	buildTree(1,1,n);
	
	for(int i = 1; i<= 2*n; i++)
		cout<<tree[i]<<" ";
	cout<<endl;

	while(1){
		int cmm,l,r;
		cin>>cmm>>l>>r;
		if(cmm == 1)
			cout<<getSum(1,1,n,l,r)<<endl;
		else
			update(1,1,n,l,r-vals[l]);
	}
	return 0;
}
