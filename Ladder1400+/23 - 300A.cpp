#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n;
int vals[110];

vector<int> g1,g2,g3;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int npos = 0, nneg = 0;
	for(int i=0;i<n;i++){
		cin>>vals[i];
		if(vals[i] < 0) nneg++;
		if(vals[i] > 0) npos++;
	}

	if(npos){
		int donepos = 0, doneneg = 0;
		for(int i = 0; i<n;i++){
			if(vals[i] < 0){
				if(!doneneg){
					doneneg = 1;
					g1.push_back(vals[i]);
				}
				else{
					g3.push_back(vals[i]);
				}
			}

			else if(vals[i] > 0){
				if(!donepos){
					donepos = 1;
					g2.push_back(vals[i]);
				}
				else{
					g3.push_back(vals[i]);
				}
			}
			else{
				g3.push_back(vals[i]);
			}

		}
	}
	else{

		int done1 = 0, donetwo = 0;

		for(int i = 0; i<n; i++){
			if(vals[i] < 0){
				if(!done1){
					done1 = 1;
					g1.push_back(vals[i]);
				}
				else if(donetwo != 2){
					donetwo++;
					g2.push_back(vals[i]);
				}
				else
					g3.push_back(vals[i]);
			}
			else
				g3.push_back(vals[i]);
		}


	}

	cout<<g1.size();
	for(int i=0;i<g1.size();i++)
		cout<<" "<<g1[i];
	cout<<endl<<g2.size();
	for(int i=0;i<g2.size();i++)
		cout<<" "<<g2[i];
	cout<<endl<<g3.size();
	for(int i=0;i<g3.size();i++)
		cout<<" "<<g3[i];
	cout<<endl;
	return 0;
}
