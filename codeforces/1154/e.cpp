#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;

typedef struct Node{
	struct Node *before,*next;
	int id;

	Node(){}

	Node(int i){
		id = i;
		before = next = NULL;
	}
}Node;

pair<pair<LL,LL>,Node*> points[maxN]; // Value, Id, Pointer
LL n,k;
LL val;
Node *vec;
Node *last;
map<int,int> team;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	vec = NULL;
	for(int i = 0; i < n; i++){
		cin>>val;
		Node *newNode = new Node(i);
		if(vec == NULL){
			vec = newNode;
			last = newNode;
		}else{
			last->next = newNode;
			newNode->before = last;
			last = newNode;
		}
		points[i] = mp(mp(val,i),newNode);
	}

	sort(points,points+n);
	int curTeam = 1;
	int pt0 = n-1;

	while(pt0 >= 0){
		if(team[points[pt0].ss->id] != 0){
			pt0--;
			continue;
		}
		Node *start = points[pt0].ss;
		team[start->id] = curTeam;
		int count = 0;
		

		Node *r = start->next;

		while(r != NULL && count < k){
			if(team[r->id] == 0){
				team[r->id] = curTeam;
				count++;
				//cout<<"ID "<<r->id<<" team "<<curTeam<<endl;
			}
			r = r->next;
		}

		count = 0;
		Node *l = start->before;

		while(l != NULL && count < k){
			if(team[l->id] == 0){
				team[l->id] = curTeam;
				count++;
				//cout<<"ID "<<l->id<<" team "<<curTeam<<endl;
			}
			 l = l->before;
		}
		if(r == NULL && l == NULL){
			vec = NULL;
		}
		else if(r == NULL){
			l->next = NULL;
		}else if(l == NULL){
			r->before = NULL;
		}else{
			l->next = r;
			r->before = l;
		}

		if(curTeam == 1) curTeam = 2;
		else curTeam = 1;
	}

	for(int i = 0; i < n; i++)
		cout<<team[i];
	cout<<endl;
	return 0;
}
