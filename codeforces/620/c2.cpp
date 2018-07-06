#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define fi first
#define se second
#define pair pair<LL,LL>

typedef struct{
	LL val,pos;
}Tipo;

LL n;


bool compare(const Tipo &a, const Tipo &b){
	return a.val < b.val;
}

bool comparePair(const pair &a, const pair &b){
	return a.se < b.se;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	Tipo tipos[101234];
	LL countT = 0;
	for(LL i=0;i<n;i++){
		LL v;
		cin>>v;
		Tipo aux;
		aux.val = v;
		aux.pos=i;

		tipos[countT++] = aux;
	}

	sort(tipos,tipos+n,compare);

	


	pair possibles[101234];
	LL possibleCount = 0;
	LL left = 0;
	for(LL i = 1; i < n; i++){
		if(tipos[i].val == tipos[left].val){
			for(LL k = left; k < i; k++)
				possibles[possibleCount++] = make_pair(tipos[k].pos,tipos[i].pos);
		}
		else
			left = i;
	}

	// for(LL i=0; i<n; i++)
	// 	cout<<tipos[i].val<<"("<<tipos[i].pos<<")\n";
	// cout<<endl<<endl;


	if(possibleCount == 0){
		cout<<"-1"<<endl;
		return 0;
	}

	if(possibleCount == 1){
		cout<<1<<endl;
		cout<<1<<" "<<n<<endl;
		return 0;
	}

	sort(possibles,possibles+possibleCount,comparePair);

	pair segments[101234];
	LL segmentsCount = 0;

	LL verify[possibleCount] = {0};
	LL goodCount = possibleCount;
	// for(LL i = 0; i<possibles.size(); i++)
	// 	cout<<possibles[i].fi << " "<<possibles[i].se<<endl;
	LL mostLeft = 0;
	while(goodCount > 0){
		int v = 0;
		while(verify[v] == 1) v++;

		possibles[v].fi = mostLeft;
		mostLeft = possibles[v].se + 1;
		segments[segmentsCount++] = possibles[v];
		LL a = possibles[v].fi;
		LL b = possibles[v].se;
		
		//cout<<"add segmento "<<possibles[0].fi <<" "<<possibles[0].se<<endl;
		for(LL k = v; k<possibleCount; k++){
			//cout<<"Teste se "<<possibles[k].fi <<" <= "<<b<<endl;
			if(!verify[k] && (possibles[k].fi <= b)){
				verify[k] = 1;
				goodCount--;
				k=-1;
			}
		}
	}

	segments[segmentsCount-1].se = (n-1);
	cout<<segmentsCount<<endl;
	for(LL i = 0; i<segmentsCount; i++)
		cout<<segments[i].fi+1<<" "<<segments[i].se+1<<endl;

	return 0;
}
