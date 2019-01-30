
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

typedef struct Node{
	int totalToLeft;
	int totalToRight;

	int timeLeft;
	int timeRight;

	Node(){}
	Node(int tl, int tr, int timeL, int timeR){
		totalToLeft = tl;
		totalToRight = tr;
		timeLeft = timeL;
		timeRight = timeR;
	}

}Node;

const int maxN = 201234;

map<int,Node*> hh;
int q;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>q;
	q--;
	char c;
	int id;
	cin>>c>>id;
	hh[id] = new Node(0,0,0,0);

	int totalL = 0, totalR = 0;
	while(q--){
		cin>>c>>id;
		if(c == 'L' || c == 'R'){
			int totalToLeft, totalToRight;
			if(c == 'L'){
				totalToLeft = 0;
				totalToRight = totalL + totalR + 1;
			}else{
				totalToRight = 0;
				totalToLeft = totalL + totalR + 1;
			}
			if(c=='L')  totalL++;
			else		totalR++;
			hh[id] = new Node(totalToLeft,totalToRight,totalL,totalR);
		}else{
			Node *n = hh[id];
			/*cout<<"currL: "<<totalL<<endl;
			cout<<"timeL: " <<n->timeLeft<<endl;
			cout<<"totL: "<<n->totalToLeft<<endl;
			cout<<"currR: "<<totalR<<endl;
			cout<<"timeR: " <<n->timeRight<<endl;
			cout<<"totR: "<<n->totalToRight<<endl;*/

			int nLeft = totalL - n->timeLeft + n->totalToLeft;
			int nRight = totalR - n->timeRight + n->totalToRight;
			cout<<min(nLeft,nRight)<<endl;
		}
	}
	return 0;
}
